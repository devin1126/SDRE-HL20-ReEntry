clf
clear all

global nodeDist LocArrays

%% DEFINE THE 3-D MAP ARRAY
MAX_X=5;
MAX_Y=5;
MAX_Z=5;

%% Map Properties
max_alt = 15000;
max_lat = 3;
min_lat = -3;
max_lon = 3;
min_lon = -3;

axis([min_lon-1 max_lon+1 min_lat-1 max_lat+1 0 max_alt+5])
grid on;
hold on;

%This array stores the coordinates of the map and the 
%Objects in each coordinate
MAP=2*(ones(MAX_X, MAX_Y, MAX_Z));

%% Inital LatLonAlt
lonStart = -3;
latStart = 3;
altStart = 15000;

%% Mapping & Plotting Starting Position
[lonStart_ind, latStart_ind, altStart_ind] = WaypointMapperLLH(lonStart, latStart, altStart, max_lon, max_lat, max_alt,-max_lon, -max_lat, 0);
MAP(lonStart_ind, latStart_ind, altStart_ind) = 1;
plot3(lonStart, latStart, altStart, 'bo');
text(lonStart+0.5,latStart+0.5, altStart+0.5,'Start')


%% Goal LatLonAlt
lonTarget = 3;
latTarget = -3;
altTarget = 0;


%% Mapping & Plotting Goal Position
[lonTarget_ind, latTarget_ind, altTarget_ind] = WaypointMapperLLH(lonTarget, latTarget, altTarget, max_lon, max_lat, max_alt,-max_lon, -max_lat, 0);
MAP(lonTarget_ind, latTarget_ind, altTarget_ind) = 0;   %Initialize MAP with location of the target
plot3(lonTarget,latTarget, altTarget,'gd');
text(lonTarget+0.5,latTarget+0.5, altTarget+0.5,'Target')

%% Mapping & Plotting Obstacles
iter_arrayX = LocArrays.lon_array;
iter_arrayY = LocArrays.lat_array;
iter_arrayZ = LocArrays.alt_array;

ObsCoor = ObstacleTracker(); % Obstacle Coordinates Array
num_Obs = size(ObsCoor,1);
real_Obs = [];
iter = 1;
dummy_obs_array = linspace(15000,0,25);
obs_dist = dummy_obs_array(2) - dummy_obs_array(1);
for i=0:24
    %curr_alt = iter_arrayZ(i);
    curr_alt = max_alt + i*obs_dist;
    for j=1:num_Obs
        curr_coor = ObsCoor(j,:);
        plot3(curr_coor(1), curr_coor(2), curr_alt, 'ro')
        real_Obs(iter,:) = [curr_coor(1), curr_coor(2), curr_alt];
        iter = iter+1;
    end
end


for i=1:size(real_Obs,1)
    for j=1:MAX_X
        for k=1:MAX_Y
            for l=1:MAX_Z
                if(real_Obs(i,1) == iter_arrayX(j) && real_Obs(i,2) == iter_arrayY(k) && real_Obs(i,3) == iter_arrayZ(l))
                    [lonObs_ind,latObs_ind,altObs_ind] = WaypointMapperLLH(real_Obs(i,1), real_Obs(i,2), real_Obs(i,3), max_lon, max_lat, max_alt, min_lon, min_lat, 0);
                    MAP(lonObs_ind,latObs_ind,altObs_ind) = -1; 
                end
            end
        end
    end
end


%% End of obstacle-Target pickup

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%LISTS USED FOR ALGORITHM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%OPEN LIST STRUCTURE
%--------------------------------------------------------------------------
%IS ON LIST 1/0 |Lon val |Lat val |Alt val |Parent Lon val |Parent Lat val |Parent Alt val |h(n) |g(n)|f(n)|
%--------------------------------------------------------------------------
OPEN=[];

%CLOSED LIST STRUCTURE
%--------------
%Lon val | Lat val | Alt val
%--------------

CLOSED=[];

%Put all obstacles on the Closed list
count = 1;%Dummy counter
for i=1:MAX_X
    for j=1:MAX_Y
        for k=1:MAX_Z
            if(MAP(i,j,k) == -1)
                CLOSED(count,1)=iter_arrayX(i); 
                CLOSED(count,2)=iter_arrayY(j);
                CLOSED(count,3)=iter_arrayZ(k);
                count=count+1;
            end
        end
    end
end

CLOSED_COUNT=size(CLOSED,1);

%set the starting node as the first node
lonNode = lonStart;
latNode = latStart;
altNode = altStart;
OPEN_COUNT = 1;
path_cost = 0;
goal_distance=distance(lonNode,latNode,altNode,lonTarget,latTarget,altTarget);
OPEN(OPEN_COUNT,:)=insert_open(lonNode,latNode,altNode,lonNode,latNode,altNode,path_cost,goal_distance,goal_distance);
OPEN(OPEN_COUNT,1)=0;
CLOSED_COUNT=CLOSED_COUNT+1;
CLOSED(CLOSED_COUNT,1)=lonNode;
CLOSED(CLOSED_COUNT,2)=latNode;
CLOSED(CLOSED_COUNT,3)=altNode;
NoPath=1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% START ALGORITHM
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NOTE: Determine additional heuristic that tracks current distance to
% nearest obstacle
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
while((lonNode ~= lonTarget || latNode ~= latTarget || altNode ~= altTarget) && NoPath == 1)
% NOTE: x = Longitude, y = Latitude, z = Altitude
 exp_array=expand_array(lonNode,latNode,altNode,path_cost,lonTarget,latTarget,altTarget,CLOSED,max_lon,max_lat,max_alt);
 exp_count=size(exp_array,1);
 %UPDATE LIST OPEN WITH THE SUCCESSOR NODES
 %OPEN LIST FORMAT
 %--------------------------------------------------------------------------
 %IS ON LIST 1/0 |Lon val |Lat val |Alt val |Parent Lon val |Parent Lat val |Parent Alt val |h(n) |g(n)|f(n)|
 %--------------------------------------------------------------------------
 %EXPANDED ARRAY FORMAT
 %--------------------------------
 %|Lon val |Lat val |Alt val |h(n) |g(n)|f(n)| (6 elements)
 %--------------------------------
 for i=1:exp_count
    flag=0;
    for j=1:OPEN_COUNT
        if(exp_array(i,1) == OPEN(j,2) && exp_array(i,2) == OPEN(j,3) && exp_array(i,3) == OPEN(j, 4))
            OPEN(j,10)=min(OPEN(j,10),exp_array(i,6)); %#ok<*SAGROW>
            if OPEN(j,8)== exp_array(i,6)
                %UPDATE PARENTS,g(n),h(n)
                OPEN(j,5)=lonNode;
                OPEN(j,6)=latNode;
                OPEN(j,7)=altNode;
                OPEN(j,8)=exp_array(i,4); %h(n)
                OPEN(j,9)=exp_array(i,5); %g(n)
            end
            flag=1;
        end
    end
    
    if flag == 0
        OPEN_COUNT = OPEN_COUNT+1;
        OPEN(OPEN_COUNT,:)=insert_open(exp_array(i,1),exp_array(i,2),exp_array(i,3),lonNode,latNode,altNode,exp_array(i,4),exp_array(i,5),exp_array(i,6));
    end
 end
 
 %Find out the node with the smallest fn 
 index_min_node = min_fn(OPEN,OPEN_COUNT,lonTarget,latTarget,altTarget);
 if (index_min_node ~= -1)    
     %Set lonNode and latNode to the node with minimum fn
     lonNode=OPEN(index_min_node,2);
     latNode=OPEN(index_min_node,3);
     altNode=OPEN(index_min_node,4);
     path_cost=OPEN(index_min_node,8);%Update the cost of reaching the parent node
  
     %Move the Node to list CLOSED
     CLOSED_COUNT=CLOSED_COUNT+1;
     CLOSED(CLOSED_COUNT,1)=lonNode;
     CLOSED(CLOSED_COUNT,2)=latNode;
     CLOSED(CLOSED_COUNT,3)=altNode;
     OPEN(index_min_node,1)=0;
 else
      NoPath=0;%Exits the loop!
 end
 
end
 
%Once algorithm has run The optimal path is generated by starting of at the
%last node(if it is the target node) and then identifying its parent node
%until it reaches the start node.This is the optimal path

i=size(CLOSED,1);
Optimal_path=[];
lon_val=CLOSED(i,1); %Target Longitude
lat_val=CLOSED(i,2); %Target Latitude
alt_val=CLOSED(i,3); %Target Altitude
i=1;
Optimal_path(i,1)=lon_val;
Optimal_path(i,2)=lat_val;
Optimal_path(i,3)=alt_val;
i=i+1;

if ((lon_val == lonTarget) && (lat_val == latTarget) && (alt_val == altTarget))
   inode=0;
   %Traverse OPEN and determine the parent nodes
   parent_lon=OPEN(node_index(OPEN,lon_val,lat_val,alt_val),5);%node_index returns the index of the node
   parent_lat=OPEN(node_index(OPEN,lon_val,lat_val,alt_val),6);
   parent_alt=OPEN(node_index(OPEN,lon_val,lat_val,alt_val),7);
   
   while( parent_lon ~= lonStart || parent_lat ~= latStart || parent_alt ~= altStart)
           Optimal_path(i,1) = parent_lon;
           Optimal_path(i,2) = parent_lat;
           Optimal_path(i,3) = parent_alt;
           %Get the grandparents:-)
           inode=node_index(OPEN,parent_lon,parent_lat,parent_alt);
           parent_lon = OPEN(inode,5);%node_index returns the index of the node
           parent_lat = OPEN(inode,6);
           parent_alt = OPEN(inode,7);
           i=i+1;
   end
 j=size(Optimal_path,1);
 %Plot the Optimal Path!
 
 rotate3d on
 xlabel('Longitude'), ylabel('Latitude'), zlabel('Altitude'), title("HL-20's Waypoint Guidance Path")
 
 p=plot3(Optimal_path(j,1),Optimal_path(j,2),Optimal_path(j,3),'bo');
 j=j-1;
 for i=j:-1:1
  pause(.25);
  set(p,'XData',Optimal_path(i,1),'YData',Optimal_path(i,2),'ZData',Optimal_path(i,3));
 drawnow ;
 end
 plot3(Optimal_path(:,1),Optimal_path(:,2),Optimal_path(:,3));
else
 pause(1);
 h=msgbox('Sorry, No path exists to the Target!','warn');
 uiwait(h,5);
end



    





