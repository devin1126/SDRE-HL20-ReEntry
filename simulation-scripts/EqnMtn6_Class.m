function dx = EqnMtn6(xo, uu, time)

%% Controls
da = uu(1);
de = uu(2);
dr = uu(3);
dfp = uu(4);
dfn = uu(5);
ddf = uu(6);

%% Declaring Variables
rm_ned = zeros(3,1);
vm_body = zeros(3,1);
wm_body = zeros(3,1);

%% Parsing State Vector
rm_ned(1) = xo(1);
rm_ned(2) = xo(2);
rm_ned(3) = xo(3);
vm_body(1) = xo(4);
vm_body(2) = xo(5);
vm_body(3) = xo(6);
wm_body(1) = xo(7);
wm_body(2) = xo(8);
wm_body(3) = xo(9);
roll       = xo(10);
pitch      = xo(11);
yaw        = xo(12);
alt        = -xo(3);

%% Transformation (NED to Body)
Tr_BN = Tr1(roll)*Tr2(pitch)*Tr3(yaw);
Tr_NB = Tr_BN';

BB = [
    1, sin(roll)*tan(pitch), cos(roll)*tan(pitch)
    0, cos(roll), -sin(roll)
    0, sin(roll)/cos(pitch), cos(roll)/cos(pitch) 
    ];
%% Mass Properties
[m, II, x_cg] = MassProps();

%% Airspeed
% vm_windrel_body = vm_body - wind_body;
airspeed = norm(vm_body);

%% Computing Flight Parameters
if( airspeed > 0.0 )
    alpha  = atan2( vm_body(3),vm_body(1)  );
    beta   = asin( vm_body(2)/airspeed );
else
    alpha  = 0.0;
    beta   = 0.0;
end

%% Call to Atmosphere
atmout = Atmosphere(alt, airspeed);
Press  = atmout(1);
Temp   = atmout(2);
rho    = atmout(3);
aa     = atmout(4);
qbar   = atmout(5);
Mach   = atmout(6);

%% Forces and Moments on Body

alpha_deg = alpha*180/pi;
beta_deg = beta*180/pi;
pp = wm_body(1);
qq = wm_body(2);
rr = wm_body(3);

[Fx,Fy,Fz, Mx,My,Mz] = HL20_Aero( qbar, airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);
faero_body = [
    Fx
    Fy
    Fz
    ];

%% Aero Moments
maero_body = [
    Mx
    My
    Mz
    ];

%% Computing Weight
fweight_ned = m*[0;0;9.80665];
fweight_body = Tr_BN*fweight_ned;

Ftot_body = faero_body + fweight_body;
Mtot_body = maero_body;
%% Derivatives

% Dynamic Equations
dx1 = (Ftot_body(1) / m) + (vm_body(2) * wm_body(3)) - (vm_body(3) * wm_body(2));
dx2 = (Ftot_body(2) / m) + (wm_body(1) * vm_body(3)) - (wm_body(3) * vm_body(1));
dx3 = (Ftot_body(3) / m) + (wm_body(2) * vm_body(1)) - (wm_body(1) * vm_body(2));
dx4 = ((Mtot_body(1) + (wm_body(2) * wm_body(3)) * (II(2,2) - II(3,3)))) / II(1,1);
dx5 = ((Mtot_body(2) + (wm_body(1) * wm_body(3)) * (II(3,3) - II(1,1)))) / II(2,2);
dx6 = ((Mtot_body(3) + (wm_body(1) * wm_body(2)) * (II(1,1) - II(2,2)))) / II(3,3);

% Kinematic
dxr = Tr_NB*vm_body;  %% Position Derivative (NED)
dxe = BB*wm_body; %% Derivative of Euler Orientation (Roll, Pitch, Yaw)

% Dynamics Equations
%dx1 = 1/m*(Ftot_body - cross(wm_body, m*vm_body)); % Linear Accelarations
%dx2 = II^-1*(Mtot_body - cross(wm_body, II*wm_body));  % Angular Accelerations


dx = [
    dxr
    dx1
    dx2
    dx3
    dx4
    dx5
    dx6
    dxe
    ];

