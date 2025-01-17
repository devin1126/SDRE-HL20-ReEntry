
YNET = zeros(length(YY),1);
DYNET = zeros(length(YY),1);

for i = 1:length(T2)
    time = T2(i);
    
    pp = [time; LON0(1); LAT0(1); ALT0(1); AZ0(1); GAMMA0(1); VMAG0(1); ALPHA0(1); ROLL0(1)];
    
    %% Evaluating Neural Net Based On Training Data
    YNET = net.NN_Eval(pp);
    
    %% Capturing Predicted Output
    LON_NN(i) = YNET(1);
    LAT_NN(i) = YNET(2);
    ALT_NN(i) = YNET(3);
    AZ_NN(i) = YNET(4);
    GAMMA_NN(i) = YNET(5);
    VMAG_NN(i) = YNET(6);
    ALPHA_NN(i) = YNET(7);
    ROLL_NN(i) = YNET(8);
    
end

% Compare Data to Training Data
figure
subplot(3,1,1)
hold on
plot(TT(i1), LAT(i1),'b')
plot(T2, LAT_NN,'r')
grid
xlabel('Time (s)')
ylabel('Latitude (deg)')
legend('Truth','Neural Net')
subplot(3,1,2)
hold on
plot(TT(i1), LON(i1),'b')
plot(T2, LON_NN,'r')
grid
xlabel('Time (s)')
ylabel('Longitude (deg)')
legend('Truth','Neural Net')
subplot(3,1,3)
hold on
plot(TT(i1), ALT(i1),'b')
plot(T2, ALT_NN,'r')
grid
xlabel('Time (s)')
ylabel('Altitude (m)')
legend('Truth','Neural Net')

figure
subplot(2,1,1)
hold on
plot(TT(i1), ALPHA(i1),'b')
plot(T2, ALPHA_NN,'r')
grid
xlabel('Time (s)')
ylabel('Alpha (deg)')
legend('Truth','Neural Net')
subplot(2,1,2)
hold on
plot(TT(i1), ROLL(i1),'b')
plot(T2, ROLL_NN,'r')
grid
xlabel('Time (s)')
ylabel('Roll (deg)')
legend('Truth','Neural Net')
