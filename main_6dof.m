clc
clear all
close all

addpath(genpath('Aerodynamics'));

%% Initialization 

% Needed Constants
r2d = pi / 180;

% Time parameters
time = 0;
tfinal = 100;
dt = 0.001; %1000Hz or 1 ms / step

% Print Parameters
time_print = 0;
time_write = 0;
dt_print = 1.00;
dt_write = 0.01;


% Initial States
V_B = [5000;0;0]; % m/s in respect to the body
u = V_B(1);
v = V_B(2);
w = V_B(3);

W_B = [0;0;0]; % rad/s in respect to the body
p = W_B(1);
q = W_B(2);
r = W_B(3);

euler = [0; 0; 0];

roll = euler(1);
pitch = euler(2);
yaw = euler(3);

alt = 4000; % meters

pos = [0;0;-alt]; % Position Vector in respect to NED frame

% Control Vector
uvec = zeros(6,1);

% State Vector
xo = [pos;u;v;w;p;q;r;roll;pitch;yaw];

%% Initial Output  
vehout = Output6NED(xo, uvec, time, dt);  % Vehicle Data Output


%% Simulation Loop
ii = 1;  % Loop Counter
while(time <= tfinal)
    % Printing Sim Updates
    if time >= time_print
        fprintf('Time = %10.5f, Altitude = %10.5f, Vmag = %10.5f, Alpha = %10.5f, Roll = %10.5f\n',time, vehout.pos.altitude, vehout.vel.vmag, vehout.airdata.alpha*r2d, vehout.euler.roll*r2d );
        time_print = time_print + dt_print;
    end
    
    % Capture Outputs
    if time >= time_write
        TIME(ii) = time;
        ALT(ii) = -xo(3);
        VMAG(ii)  = vehout.vel.vmag;
        MACH(ii) = vehout.airdata.Mach;
        ALPHA(ii) = vehout.airdata.alpha*r2d;
        BETA(ii)  = vehout.airdata.beta*r2d;
        ROLL(ii)  = vehout.euler.roll*r2d;
        PITCH(ii) = vehout.euler.pitch*r2d;
        YAW(ii)   = vehout.euler.yaw*r2d;
        VX(ii)    = vehout.vel.vm_body(1);
        VY(ii)    = vehout.vel.vm_body(2);
        VZ(ii)    = vehout.vel.vm_body(3);
        WX(ii)    = vehout.rates.wm_bi_body(1);
        WY(ii)    = vehout.rates.wm_bi_body(2);
        WZ(ii)    = vehout.rates.wm_bi_body(3);
        AX(ii)    = vehout.accels.fsp_body(1);
        AY(ii)    = vehout.accels.fsp_body(2);
        AZ(ii)    = vehout.accels.fsp_body(3);
        
        ii = ii + 1;
        time_write = time_write + dt_write;
    end
  
    
    % Onboard Software (Guidance, Nav, & Control)
    
    % Actuators (Z-Domain Transfer Function)
    
    % Integration (RK4)
    xo = Integrater_RK4(xo, uvec, time, dt, @EqnMtn6);
   % xo = xo + EqnMtn6(xo)*dt;
    % Flight Stopping Critera
    if vehout.pos.altitude < 0
        disp(['Plane Landed! Altitude < 0 at t = ' num2str(time) ' sec']);
        break
    end
    
    % Output Equations
    vehout = Output6NED(xo,uvec,time,dt);
    
    % Time Update
    time = time + dt;
end

%% Plots
figure, clf
plot(TIME,ALT)
title('Time vs Altitude for 6-DOF Airplane Simulation')
xlabel('Time (s)'), ylabel('Altitude (m)')
set(gca, 'fontsize', 12)
