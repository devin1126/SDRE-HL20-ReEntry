function exp_array=expand_array(node_lon,node_lat,node_alt,hn,lonTarget,latTarget,altTarget,CLOSED,MAX_LON,MAX_LAT,MAX_ALT)
    %Function to return an expanded array
    %This function takes a node and returns the expanded list
    %of successors,with the calculated fn values.
    %The criteria being none of the successors are on the CLOSED list.
    format longG
    global nodeDist
    
    lonDist = nodeDist.lonDist;
    latDist = nodeDist.latDist;
    altDist = nodeDist.altDist;
    
    exp_array=[];
    exp_count=1;
    c2=size(CLOSED,1);%Number of elements in CLOSED including the zeros
    for i= lonDist:-lonDist:-lonDist
        for j= latDist:-latDist:-latDist
            for k= altDist:-altDist:-altDist
                if (i~=j || i~=0 || k ~=0)  %The node itself is not its successor
                    s_lon = node_lon+i;
                    s_lat = node_lat+j;
                    s_alt = node_alt+k;
                    
                    if( (s_lon >= -MAX_LON && s_lon <=MAX_LON) && (s_lat >= -MAX_LAT && s_lat <=MAX_LAT) && (s_alt >= 0 && s_alt <=MAX_ALT))     %node within array bound
                        flag = 1;                    
                        for c1=1:c2
                            if(s_lon == CLOSED(c1,1) && s_lat == CLOSED(c1,2) && s_alt == CLOSED(c1,3))
                                flag = 0;
                            end
                        end             %End of for loop to check if a successor is on closed list.
                        if (flag == 1)
                            exp_array(exp_count,1) = s_lon;
                            exp_array(exp_count,2) = s_lat;
                            exp_array(exp_count,3) = s_alt;
                            exp_array(exp_count,4) = hn+distance(node_lon,node_lat,node_alt,s_lon,s_lat,s_alt);%cost of travelling to node
                            exp_array(exp_count,5) = distance(lonTarget,latTarget,altTarget,s_lon,s_lat,s_alt);%distance between node and goal
                            exp_array(exp_count,6) = exp_array(exp_count,4)+exp_array(exp_count,5);%fn
                            exp_count=exp_count+1;
                        end%Populate the exp_array list!!!
                    end
                end
            end
        end
    end 
end