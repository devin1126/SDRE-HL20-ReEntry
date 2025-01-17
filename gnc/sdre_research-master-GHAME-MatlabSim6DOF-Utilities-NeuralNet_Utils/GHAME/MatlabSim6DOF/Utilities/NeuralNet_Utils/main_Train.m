clc
clear all
close all
format long g
format compact

data = readtable('DATAOUT.csv');

i1 = find(data.Run == 1);
i2 = find(data.Run == 2);
i3 = find(data.Run == 3);

TIME = data.Time;
LON = data.Lon;
LAT = data.Lat;
ALT = data.Alt;
GAMMA = data.Gamma;
AZ = data.Azimuth;
VMAG = data.Vmag;
ALPHA = data.Alpha;
ROLL = data.Roll;

LON1 = LON( i1(1) )*ones(length(i1),1);
LON2 = LON( i2(1) )*ones(length(i2),1);
LON3 = LON( i3(1) )*ones(length(i3),1);
LON0 = [LON1;LON2;LON3];

LAT1 = LAT( i1(1) )*ones(length(i1),1);
LAT2 = LAT( i2(1) )*ones(length(i2),1);
LAT3 = LAT( i3(1) )*ones(length(i3),1);
LAT0 = [LAT1;LAT2;LAT3];

ALT1 = ALT( i1(1) )*ones(length(i1),1);
ALT2 = ALT( i2(1) )*ones(length(i2),1);
ALT3 = ALT( i3(1) )*ones(length(i3),1);
ALT0 = [ALT1;ALT2;ALT3];

GAMMA1 = GAMMA( i1(1) )*ones(length(i1),1);
GAMMA2 = GAMMA( i2(1) )*ones(length(i2),1);
GAMMA3 = GAMMA( i3(1) )*ones(length(i3),1);
GAMMA0 = [GAMMA1;GAMMA2;GAMMA3];

AZ1 = AZ( i1(1) )*ones(length(i1),1);
AZ2 = AZ( i2(1) )*ones(length(i2),1);
AZ3 = AZ( i3(1) )*ones(length(i3),1);
AZ0 = [AZ1;AZ2;AZ3];

VMAG1 = VMAG( i1(1) )*ones(length(i1),1);
VMAG2 = VMAG( i2(1) )*ones(length(i2),1);
VMAG3 = VMAG( i3(1) )*ones(length(i3),1);
VMAG0 = [VMAG1;VMAG2;VMAG3];

ALPHA1 = ALPHA( i1(1) )*ones(length(i1),1);
ALPHA2 = ALPHA( i2(1) )*ones(length(i2),1);
ALPHA3 = ALPHA( i3(1) )*ones(length(i3),1);
ALPHA0 = [ALPHA1; ALPHA2; ALPHA3];

ROLL1 = ROLL( i1(1) )*ones(length(i1),1);
ROLL2 = ROLL( i2(1) )*ones(length(i2),1);
ROLL3 = ROLL( i3(1) )*ones(length(i3),1);
ROLL0 = [ROLL1;ROLL2;ROLL3];

%% Input Data
T2 = 0:0.01:50;
TT = TIME;

%% Training Data
ii = find(TIME >= 10);
PP = [TIME LON0 LAT0 ALT0 AZ0 GAMMA0 VMAG0 ALPHA0 ROLL0];
YY = [LON LAT ALT AZ GAMMA VMAG ALPHA ROLL];

%% Neural Net Test
net = NeuralNet();
net = net.NN_Initialize(9,1500,8);
net = net.NN_Train(PP,YY');
