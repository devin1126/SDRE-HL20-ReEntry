function atmout = Atmosphere(Alt, Airspeed)
% Rair = 287.0;
% 
% if Alt < 11000
%     Temp = 288.15 - 0.0065*Alt;
%     Press = 101325*(Temp/288.15)^5.2559;
% else
%     Temp = 216.0;
%     Press = 22630*exp(-0.00015769*(Alt-11000));
% end
% 
% rho = Press/(Rair*Temp);
% aa = sqrt(1.4*Rair*Temp);

[Temp, aa, Press, rho] = atmoscoesa(Alt);

qbar = 0.5*rho*Airspeed^2;
Mach = Airspeed/aa;

atmout = [Press Temp rho aa qbar Mach];
return
end
