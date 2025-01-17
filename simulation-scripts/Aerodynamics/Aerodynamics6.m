function [Fx,Fy,Fz, Mx,My,Mz] = Aerodynamics6(aero, Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg)

%% Constants
ft2m = 0.3048;
m2ft = 1/ft2m;

%% Aero Reference Values
S_ref   = 286.45/m2ft^2;            % Reference area [m^2]
d_ref   = 28.24/m2ft;               % Reference length [m]
b_ref   = 13.89/m2ft;               % Reference Span [m]

len_veh = 27.31/m2ft;               % Vehicle Length
x_ref   = 0.54*len_veh;             % Reference point from nose

moment_arm = [
    -(x_cg-x_ref) 
    0 
    0
    ];


%% Damping
Clp = interpn(aero.alpha_vec_damping, aero.Clp, abs(alpha_deg));
Cnp = interpn(aero.alpha_vec_damping, aero.Cnp, abs(alpha_deg));
Clr = interpn(aero.alpha_vec_damping, aero.Clr, abs(alpha_deg));
Cnr = interpn(aero.alpha_vec_damping, aero.Cnr, abs(alpha_deg));
Cmq = interpn(aero.alpha_vec_damping, aero.Cmq, abs(alpha_deg));


%% Datum Coeficients
CXo = interpn(aero.beta_vec_0, aero.alpha_vec_0,  aero.CX0, beta_deg, alpha_deg);
CYo = aero.CYbeta*beta_deg;
CZo = interpn(aero.beta_vec_0, aero.alpha_vec_0,  aero.CZ0, beta_deg, alpha_deg);
Clo = aero.Clbeta*beta_deg;
Cmo = interpn(aero.beta_vec_0, aero.alpha_vec_0,  aero.Cm0, beta_deg, alpha_deg);
Cno = interpn(aero.alpha_vec_Cn0, aero.beta_vec_Cn0,  aero.Cn0, alpha_deg, abs(beta_deg))*sign(beta_deg);

%% Actuator Deflection Coeficients
% Aileron
CXda = interpn(aero.alpha_vec_0, aero.CXda, alpha_deg);
CYda = interpn(aero.alpha_vec_0, aero.CYda, alpha_deg);
CZda = interpn(aero.alpha_vec_0, aero.CZda, alpha_deg);
Clda = interpn(aero.alpha_vec_0, aero.Clda, alpha_deg);
Cmda = interpn(aero.alpha_vec_0, aero.Cmda, alpha_deg);
Cnda = interpn(aero.alpha_vec_0, aero.Cnda, alpha_deg);

% Elevator
CXde = interpn(aero.alpha_vec_0, aero.CXde, alpha_deg);
CYde = 0;
CZde = interpn(aero.alpha_vec_0, aero.CZde, alpha_deg);
Clde = 0;
Cmde = interpn(aero.alpha_vec_0, aero.Cmde, alpha_deg);
Cnde = 0;

% Rudder
CXdr = interpn(aero.alpha_vec_0, aero.CXdr, alpha_deg);
CYdr = interpn(aero.alpha_vec_0, aero.CYdr, alpha_deg);
CZdr = interpn(aero.alpha_vec_0, aero.CZdr, alpha_deg);
Cldr = interpn(aero.alpha_vec_0, aero.Cldr, alpha_deg);
Cmdr = interpn(aero.alpha_vec_0, aero.Cmdr, alpha_deg);
Cndr = interpn(aero.alpha_vec_0, aero.Cndr, alpha_deg);

%% Flaps
% Positive
CXdfp = interpn(aero.alpha_vec_0, aero.CXdfp, alpha_deg);
CYdfp = 0;
CZdfp = interpn(aero.alpha_vec_0, aero.CZdfp, alpha_deg);
Cldfp = 0;
Cmdfp = interpn(aero.alpha_vec_0, aero.Cmdfp, alpha_deg);
Cndfp = 0;

% Negative
CXdfn = interpn(aero.alpha_vec_0, aero.CXdfn, alpha_deg);
CYdfn = 0;
CZdfn = interpn(aero.alpha_vec_0, aero.CZdfn, alpha_deg);
Cldfn = 0;
Cmdfn = interpn(aero.alpha_vec_0, aero.Cmdfn, alpha_deg);
Cndfn = 0;

% Differential
CXddf = interpn(aero.alpha_vec_0, aero.CXddf, alpha_deg);
CYddf = interpn(aero.alpha_vec_0, aero.CYddf, alpha_deg);
CZddf = 0;
Clddf = interpn(aero.alpha_vec_0, aero.Clddf, alpha_deg);
Cmddf = 0;
Cnddf = interpn(aero.alpha_vec_0, aero.Cnddf, alpha_deg);

%% Dimensionalizing 
Fx = Qbar*S_ref*(CXo + CXda*abs(da) + CXde*de + CXdr*abs(dr) + CXdfp*dfp + CXdfn*dfn + CXddf*abs(ddf));
Fy = Qbar*S_ref*(CYo + CYda*da + CYde*de + CYdr*dr + CYdfp*dfp + CYdfn*dfn + CYddf*ddf);
Fz = Qbar*S_ref*(CZo + CZda*abs(da) + CZde*de + CZdr*abs(dr) + CZdfp*dfp + CZdfn*dfn + CZddf*ddf);

Mx = Qbar*S_ref*b_ref*(Clo + Clp*(b_ref/2)/Airspeed*pp + Clr*(b_ref/2)/Airspeed*rr + Clda*da + Clde*de + Cldr*dr + Cldfp*dfp + Cldfn*dfn + Clddf*ddf);
My = Qbar*S_ref*d_ref*(Cmo + Cmq*(d_ref/2)/Airspeed*qq + Cmda*abs(da) + Cmde*de + Cmdr*abs(dr) + Cmdfp*dfp + Cmdfn*dfn + Cmddf*ddf);
Mz = Qbar*S_ref*b_ref*(Cno + Cnp*(b_ref/2)/Airspeed*pp + Cnr*(b_ref/2)/Airspeed*rr + Cnda*da + Cnde*de + Cndr*dr + Cndfp*dfp + Cndfn*dfn + Cnddf*ddf);

%% Forces and Moments
faero_body = [
    Fx
    Fy
    Fz
    ];

maero_body = [
    Mx
    My
    Mz
    ];

maero_body = maero_body + cross(faero_body, moment_arm);

Mx = maero_body(1);
My = maero_body(2);
Mz = maero_body(3);

return
end
