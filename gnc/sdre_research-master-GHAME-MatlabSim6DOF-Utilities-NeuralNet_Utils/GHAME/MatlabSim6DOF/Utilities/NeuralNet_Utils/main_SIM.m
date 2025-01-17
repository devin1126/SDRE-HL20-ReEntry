clc
clear all
close all
format long g
format compact

load RUNDATA.mat

%% Input Data
T2 = 10:0.01:50;

%% Training Data
ii = find(TIME >= 10);
TT = TIME(ii);
YY = [LON(ii); LAT(ii); ALT(ii); VX(ii);VY(ii);VZ(ii);ALPHA(ii); BETA(ii); HEATING(ii)];

%% Neural Net Test
net = NeuralNet();
net = net.NN_Initialize(1,250,9);
net = net.NN_Train(TT,YY);

YNET = zeros(length(YY),1);
DYNET = zeros(length(YY),1);

for i = 1:length(T2)
    time = T2(i);
    
    %% Evaluating Neural Net Based On Training Data
    YNET = net.NN_Eval(time);
    
    %% Capturing Predicted Output
    LON_NN(i) = YNET(1);
    LAT_NN(i) = YNET(2);
    ALT_NN(i) = YNET(3);
    VX_NN(i) = YNET(4);
    VY_NN(i) = YNET(5);
    VZ_NN(i) = YNET(6);
    ALPHA_NN(i) = YNET(7);
    BETA_NN(i) = YNET(8);
    HEATING_NN(i) = YNET(9);
    
end

% Compare Data to Training Data
figure
subplot(3,1,1)
hold on
plot(TT, LAT(ii),'b')
plot(T2, LAT_NN,'r')
grid
xlabel('Time (s)')
ylabel('Latitude (deg)')
legend('Truth','Neural Net')
subplot(3,1,2)
hold on
plot(TT, LON(ii),'b')
plot(T2, LON_NN,'r')
grid
xlabel('Time (s)')
ylabel('Longitude (deg)')
legend('Truth','Neural Net')
subplot(3,1,3)
hold on
plot(TT, ALT(ii),'b')
plot(T2, ALT_NN,'r')
grid
xlabel('Time (s)')
ylabel('Altitude (m)')
legend('Truth','Neural Net')


figure
subplot(3,1,1)
hold on
plot(TT, VX(ii),'b')
plot(T2, VX_NN,'r')
grid
xlabel('Time (s)')
ylabel('Vx (m/s)')
legend('Truth','Neural Net')
subplot(3,1,2)
hold on
plot(TT, VY(ii),'b')
plot(T2, VY_NN,'r')
grid
xlabel('Time (s)')
ylabel('Vy (m/s)')
legend('Truth','Neural Net')
subplot(3,1,3)
hold on
plot(TT, VZ(ii),'b')
plot(T2, VZ_NN,'r')
grid
xlabel('Time (s)')
ylabel('Vz (m/s)')
legend('Truth','Neural Net')
figure
subplot(2,1,1)
hold on
plot(TT, ALPHA(ii),'b')
plot(T2, ALPHA_NN,'r')
grid
xlabel('Time (s)')
ylabel('Alpha (deg)')
legend('Truth','Neural Net')
subplot(2,1,2)
hold on
plot(TT, BETA(ii),'b')
plot(T2, BETA_NN,'r')
grid
xlabel('Time (s)')
ylabel('Beta (deg)')
legend('Truth','Neural Net')
figure
hold on
plot(TT, HEATING(ii),'b')
plot(T2, HEATING_NN,'r')
grid
xlabel('Time (s)')
ylabel('Heating (J)')
legend('Truth','Neural Net')