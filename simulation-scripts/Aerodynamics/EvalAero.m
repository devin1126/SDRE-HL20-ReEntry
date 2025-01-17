function aeroout = EvalAero(aero, Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg)

%% Constants
ft2m = 0.3048;
m2ft = 1/ft2m;
Sref   = 286.45/m2ft^2;            % Reference area [m^2]
cref   = 28.24/m2ft;               % Reference length [m]
bref   = 13.89/m2ft;               % Reference Span [m]


%% Nominal Aerodynamics
[Fx,Fy,Fz, Mx,My,Mz] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);

Tr_Body_Stab = Tr2(alpha_deg*pi/180);
Tr_Stab_Body = Tr_Body_Stab';
f_aero_body = [Fx; Fy; Fz];
f_aero_stab = Tr_Stab_Body*[Fx; Fy; Fz];

Drag = -f_aero_stab(1);
Lift = -f_aero_stab(3);

CD = Drag/(Sref*Qbar);
CY = Fy/(Sref*Qbar);
CL = Lift/(Sref*Qbar);
CLL = Mx/(Sref*bref*Qbar);
CM = My/(Sref*cref*Qbar);
CLN = Mz/(Sref*bref*Qbar);

CX = Fx/(Sref*Qbar);
CY = Fy/(Sref*Qbar);
CZ = Fz/(Sref*Qbar);

%% Partial Derivatives
delta_alpha_beta = 0.1;  %% Deg
delta_control = 0.1;  %% Deg

%% Alpha Sweep
pert1 = alpha_deg + delta_alpha_beta;
pert2 = alpha_deg - delta_alpha_beta;
[Fx1, Fy1, Fz1, Mx1, My1, Mz1] = HL20_Aero( Qbar, Airspeed, pert1, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);
[Fx2, Fy2, Fz2, Mx2, My2, Mz2] = HL20_Aero( Qbar, Airspeed, pert2, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);

Fxa = (Fx1 - Fx2)/(2*delta_alpha_beta);
Fya = (Fy1 - Fy2)/(2*delta_alpha_beta);
Fza = (Fz1 - Fz2)/(2*delta_alpha_beta);
Mxa = (Mx1 - Mx2)/(2*delta_alpha_beta);
Mya = (My1 - My2)/(2*delta_alpha_beta);
Mza = (Mz1 - Mz2)/(2*delta_alpha_beta);

%% Beta Sweep
pert1 = beta_deg + delta_alpha_beta;
pert2 = beta_deg - delta_alpha_beta;
[Fx1, Fy1, Fz1, Mx1, My1, Mz1] = HL20_Aero( Qbar, Airspeed, alpha_deg, pert1, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);
[Fx2, Fy2, Fz2, Mx2, My2, Mz2] = HL20_Aero( Qbar, Airspeed, alpha_deg, pert2, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg);
Fxb = (Fx1 - Fx2)/(2*delta_alpha_beta);
Fyb = (Fy1 - Fy2)/(2*delta_alpha_beta);
Fzb = (Fz1 - Fz2)/(2*delta_alpha_beta);
Mxb = (Mx1 - Mx2)/(2*delta_alpha_beta);
Myb = (My1 - My2)/(2*delta_alpha_beta);
Mzb = (Mz1 - Mz2)/(2*delta_alpha_beta);

%% DA Sweep
pert1 = da + delta_alpha_beta;
pert2 = da - delta_alpha_beta;
[Fx1, Fy1, Fz1, Mx1, My1, Mz1] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, pert1,de,dr, dfp,dfn, ddf, x_cg);
[Fx2, Fy2, Fz2, Mx2, My2, Mz2] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, pert2,de,dr, dfp,dfn, ddf, x_cg);

Fxdp = (Fx1 - Fx2)/(2*delta_alpha_beta);
Fydp = (Fy1 - Fy2)/(2*delta_alpha_beta);
Fzdp = (Fz1 - Fz2)/(2*delta_alpha_beta);
Mxdp = (Mx1 - Mx2)/(2*delta_alpha_beta);
Mydp = (My1 - My2)/(2*delta_alpha_beta);
Mzdp = (Mz1 - Mz2)/(2*delta_alpha_beta);

%% DQ Sweep
pert1 = de + delta_alpha_beta;
pert2 = de - delta_alpha_beta;
[Fx1, Fy1, Fz1, Mx1, My1, Mz1] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,pert1,dr, dfp,dfn, ddf, x_cg);
[Fx2, Fy2, Fz2, Mx2, My2, Mz2] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,pert2,dr, dfp,dfn, ddf, x_cg);

Fxdq = (Fx1 - Fx2)/(2*delta_alpha_beta);
Fydq = (Fy1 - Fy2)/(2*delta_alpha_beta);
Fzdq = (Fz1 - Fz2)/(2*delta_alpha_beta);
Mxdq = (Mx1 - Mx2)/(2*delta_alpha_beta);
Mydq = (My1 - My2)/(2*delta_alpha_beta);
Mzdq = (Mz1 - Mz2)/(2*delta_alpha_beta);

%% DR Sweep
pert1 = dr + delta_alpha_beta;
pert2 = dr - delta_alpha_beta;
[Fx1, Fy1, Fz1, Mx1, My1, Mz1] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,pert1, dfp,dfn, ddf, x_cg);
[Fx2, Fy2, Fz2, Mx2, My2, Mz2] = HL20_Aero( Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,pert2, dfp,dfn, ddf, x_cg);

Fxdr = (Fx1 - Fx2)/(2*delta_alpha_beta);
Fydr = (Fy1 - Fy2)/(2*delta_alpha_beta);
Fzdr = (Fz1 - Fz2)/(2*delta_alpha_beta);
Mxdr = (Mx1 - Mx2)/(2*delta_alpha_beta);
Mydr = (My1 - My2)/(2*delta_alpha_beta);
Mzdr = (Mz1 - Mz2)/(2*delta_alpha_beta);

%% Converting to Stability Frame
Tr_SB = Tr2(-alpha_deg*pi/180);
fbody = [
    Fxa
    Fya
    Fza
    ];

fstab = Tr_SB*fbody;
Da = -fstab(1);
La = -fstab(3);

%% Defining Aero Structure
aeroout.Fx = Fx;
aeroout.Fy = Fy;
aeroout.Fz = Fz;
aeroout.LL = Mx;
aeroout.MM = My;
aeroout.NN = Mz;
aeroout.Lo = Lift;
aeroout.La = La;
aeroout.Do = Drag;
aeroout.Da = Da;
aeroout.Fza   = Fza;
aeroout.Fzb   = Fzb;
aeroout.Fzda  = Fzdp;
aeroout.Fzde  = Fzdq;
aeroout.Fzdr  = Fzdr;
aeroout.Fxa   = Fxa;
aeroout.Fxb   = Fxb;
aeroout.Yb   = Fyb ;
aeroout.Ya   = Fya ;
aeroout.Yda  = Fydp;
aeroout.Yde  = Fydq;
aeroout.Ydr  = Fydr;
aeroout.LLa  = Mxa;
aeroout.LLb  = Mxb;
aeroout.LLda = Mxdp;
aeroout.LLde = Mxdq;
aeroout.LLdr = Mxdr;
aeroout.Ma   = Mya;
aeroout.Mb   = Myb ;
aeroout.Mda  = Mydp;
aeroout.Mde  = Mydq;
aeroout.Mdr  = Mydr;
aeroout.LNa  = Mza ;
aeroout.LNb  = Mzb ;
aeroout.LNda = Mzdp;
aeroout.LNde = Mzdq;
aeroout.LNdr = Mzdr;
aeroout.CL = CL;
aeroout.CD = CD;
aeroout.CX = CX;
aeroout.CY = CY;
aeroout.CZ = CZ;
aeroout.CLL = CLL;
aeroout.CM = CM;
aeroout.CLN = CLN;
aeroout.Lift = Lift;
aeroout.Drag = Drag;
aeroout.YY = Fy;
aeroout.faero_body = [Fx;Fy;Fz];
aeroout.maero_body = [Mx;My;Mz];

return
end


