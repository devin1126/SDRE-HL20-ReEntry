clc
clear all
close all
format long g
format compact

%% Input Data
TT = 0:0.1:10;
T2 = 0:0.1:15;
YY = 10*sin(TT);
DY = 10*cos(TT);

%% Neural Net Test
net = NeuralNet();
net = net.NN_Initialize(1,40,1);
net = net.NN_Train(TT,YY);

YNET = zeros(length(YY),1);
DYNET = zeros(length(YY),1);

for i = 1:length(T2)
    time = T2(i);
    
    %% Evaluating Neural Net Based On Training Data
    YNET(i) = net.NN_Eval(time);
    
    %% Computing Derivative
    DYNET(i) = net.DNN_Eval(time);
end

% Compare Data to Training Data
figure
hold on
plot(T2, YNET,'r')
plot(TT, YY,'b')
grid
xlabel('Time (s)')
ylabel('Yout (m)')

% Compare Derivative of NN to Known Derivative
figure
hold on
plot(T2, DYNET,'r')
plot(TT, DY,'b')
grid
xlabel('Time (s)')
ylabel('DYout (m)')