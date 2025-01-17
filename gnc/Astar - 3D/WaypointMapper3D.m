function [x_ind, y_ind, z_ind] = WaypointMapper3D(x, y, z, x_PLIM, y_PLIM, z_PLIM, x_NLIM, y_NLIM, z_NLIM)
% This function maps the coordinates of a waypoint in R^3 to the exact
% coordinates of a binary occupancy map (cube map only)

%% Coordinate-Equivalent Map Computation
iter_arrayX = x_NLIM:1:x_PLIM;
iter_arrayY = y_PLIM:-1:y_NLIM;
iter_arrayZ = z_NLIM:1:z_PLIM;

iter_arrayZ = flip(iter_arrayZ);

%% Waypoint Mapping Derivation
for i=1:1:2*x_PLIM+1
    for j=1:1:2*y_PLIM+1
        for k=1:1:2*z_PLIM+1
            if (iter_arrayX(i) == x && iter_arrayY(j) == y && iter_arrayZ(k) == z)
                x_index = i;
                y_index = j;
                z_index = k;
            end
        end
    end
end

x_ind = x_index;
y_ind = y_index;
z_ind = z_index;
end