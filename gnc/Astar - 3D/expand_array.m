function exp_array=expand_array(node_x,node_y,node_z,hn,xTarget,yTarget,zTarget,CLOSED,MAX_X,MAX_Y,MAX_Z)
    %Function to return an expanded array
    %This function takes a node and returns the expanded list
    %of successors,with the calculated fn values.
    %The criteria being none of the successors are on the CLOSED list.
    %
    %   Copyright 2009-2010 The MathWorks, Inc.
    
    exp_array=[];
    exp_count=1;
    c2=size(CLOSED,1);%Number of elements in CLOSED including the zeros
    for i= 1:-1:-1
        for j= 1:-1:-1
            for k= 1:-1:-1
                if (i~=j || i~=0 || k ~=0)  %The node itself is not its successor
                    s_x = node_x+i;
                    s_y = node_y+j;
                    s_z = node_z+k;
                    if( (s_x >= -MAX_X && s_x <=MAX_X) && (s_y >= -MAX_Y && s_y <=MAX_Y) && (s_z >= -MAX_Z && s_z <=MAX_Z))     %node within array bound
                        flag = 1;                    
                        for c1=1:c2
                            if(s_x == CLOSED(c1,1) && s_y == CLOSED(c1,2) && s_z == CLOSED(c1,3))
                                flag = 0;
                            end
                        end             %End of for loop to check if a successor is on closed list.
                        if (flag == 1)
                            exp_array(exp_count,1) = s_x;
                            exp_array(exp_count,2) = s_y;
                            exp_array(exp_count,3) = s_z;
                            exp_array(exp_count,4) = hn+distance(node_x,node_y,node_z,s_x,s_y,s_z);%cost of travelling to node
                            exp_array(exp_count,5) = distance(xTarget,yTarget,zTarget,s_x,s_y,s_z);%distance between node and goal
                            exp_array(exp_count,6) = exp_array(exp_count,4)+exp_array(exp_count,5);%fn
                            exp_count=exp_count+1;
                        end%Populate the exp_array list!!!
                    end
                end
            end
        end
    end 
end