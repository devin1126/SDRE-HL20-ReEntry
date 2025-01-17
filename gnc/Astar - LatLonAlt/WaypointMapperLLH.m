function [lon_ind, lat_ind, alt_ind] = WaypointMapperLLH(lon, lat, alt, x_PLIM, y_PLIM, z_PLIM, x_NLIM, y_NLIM, z_NLIM)
% This function maps the coordinates of a waypoint in LLH form (R^3) to the exact
% coordinates of a binary occupancy map (cube map only)
% x = Longitude
% y = Latitude
% z = Altitude

global nodeDist LocArrays

%% Coordinate-Equivalent Map Computation
iter_arrayX = linspace(x_NLIM, x_PLIM, 5);
iter_arrayY = linspace(y_PLIM, y_NLIM, 5);
iter_arrayZ = linspace(z_PLIM, z_NLIM, 5);

nodeDist.lonDist = iter_arrayX(2) - iter_arrayX(1);
nodeDist.latDist = iter_arrayY(2) - iter_arrayY(1);
nodeDist.altDist = iter_arrayZ(2) - iter_arrayZ(1);

LocArrays.lon_array = iter_arrayX;
LocArrays.lat_array = iter_arrayY;
LocArrays.alt_array = iter_arrayZ;

%% Waypoint Mapping Derivation
for i=1:1:length(iter_arrayX)
    for j=1:1:length(iter_arrayY)
        for k=1:1:length(iter_arrayZ)
            if (iter_arrayX(i) == lon && iter_arrayY(j) == lat && iter_arrayZ(k) == alt)
                x_index = i;
                y_index = j;
                z_index = k;
            end
        end
    end
end

lon_ind = x_index;
lat_ind = y_index;
alt_ind = z_index;
end