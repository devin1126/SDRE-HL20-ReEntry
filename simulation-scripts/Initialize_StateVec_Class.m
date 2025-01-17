function xo = Initialize_StateVec_Class(time, latitude, longitude, altitude, roll, pitch, yaw, vmag)
%% Global Parameters
global c

%% ECI to ECEF Transformation
Tr_EI = TR_EI(time);
Tr_IE = Tr_EI';
Tr_NE = TR_NE(latitude, longitude);
Tr_EN = Tr_NE';
Tr_BN = TR_BN(roll, pitch, yaw);
Tr_NB = Tr_BN';
Tr_BE = Tr_BN*Tr_NE;
Tr_EB = Tr_BE';
Tr_BI = Tr_BE*Tr_EI;
Tr_IB = Tr_BI';

wei_ecef = [0.0; 0.0; c.WEII3];

%% ECEF and ECI Positions
rm_ecef = LLH2ECEF(latitude, longitude, altitude);
rm_eci = Tr_IE*rm_ecef;

%% Computing Velocity Vector
vm_ned = zeros(3,1);

azimuth = yaw;
gamma = pitch;

vm_ned(1) = vmag*cos(gamma)*cos(azimuth);
vm_ned(2) = vmag*cos(gamma)*sin(azimuth);
vm_ned(3) = -vmag*sin(gamma);
vm_ecef = Tr_EN*vm_ned;
vm_eci = Tr_IE*vm_ecef + cross(Tr_IE*wei_ecef, rm_eci);

%% Computing Body Rate Vector
wm_bn_body = zeros(3,1);
wm_bi_body = wm_bn_body + Tr_BE*wei_ecef;

%% Computing State Vector
xo = zeros(12,1);
xo(1) = rm_eci(1);
xo(2) = rm_eci(2);
xo(3) = rm_eci(3);
xo(4) = vm_eci(1);
xo(5) = vm_eci(2);
xo(6) = vm_eci(3);
xo(7) = wm_bi_body(1);
xo(8) = wm_bi_body(2);
xo(9) = wm_bi_body(3);
xo(10) = roll;
xo(11) = pitch;
xo(12) = yaw;

return
end