function TRNE = TR_NE(latitude, longitude)
clat = cos(latitude);
slat = sin(latitude);
clon = cos(longitude);
slon = sin(longitude);

TRNE = [
    -slat*clon   -slat*slon   clat
    -slon         clon        0
    -clat*clon   -clat*slon   -slat
    ];

return
end