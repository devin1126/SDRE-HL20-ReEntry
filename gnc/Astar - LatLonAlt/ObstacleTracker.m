function ObsCoor = ObstacleTracker()
%   This function returns a list of coordinates belonging to the cross-sectional area of a circular
%   obstacle object in a 2D Binary Occupancy Grid (25x25) or (7x7)
global LocArrays

%% Coordinate-Equivalent Map 
iter_arrayX = LocArrays.lon_array;
iter_arrayY = LocArrays.lat_array;

%% Obstacle Index List Generation (Circular Ellipsoid)
obs_ind_list = Circular_Obstacle_5x5();
                            
%% Conversion of Obstacle Map Indices to Lat & Lon Coordinates
obs_list_size = size(obs_ind_list);
curr_coor_list = zeros(obs_list_size(1), 2);
for i=1:obs_list_size(1)
    temp_array = obs_ind_list(i,:);
    lon = iter_arrayX(temp_array(1));
    lat = iter_arrayY(temp_array(2));
    curr_coor_list(i,:) = [lon, lat];
end

ObsCoor = curr_coor_list;

end

