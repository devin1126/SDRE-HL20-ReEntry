function [mass, II, x_cg] = MassProps()

d2r     = pi/180;                 % Conversion Deg to Rad
ft2m    = 3.28084;                % feet to meter
lb2kg   = 2.20462;                % lbs to kg

%% ==================================================================
% Aircraft Mass Configurations
%==================================================================
massBody  = 22932/lb2kg;            % Mass of Body [Kg]
massFuel  = 2948/lb2kg;             % Mass of Fuel [Kg] 
mass = massBody + massFuel;

%% CG
len_veh = 27.31/ft2m;               % Vehicle Length
S_ref   = 286.45/ft2m^2;            % Reference area [m^2]
d_ref   = 28.24/ft2m;               % Reference length [m]
b_ref   = 13.89/ft2m;               % Reference Span [m]
x_ref   = 0.54*len_veh;             % Reference point from nose
x_cg    = 0.575*len_veh;            % Center of Gravity (Full)

%% Inertia
Ixx     = 1/8*mass*(S_ref/pi);
Iyy     = 1/3*mass*(d_ref/2)^2;
Izz     = Iyy;
II = diag([Ixx Iyy Izz]);

end

