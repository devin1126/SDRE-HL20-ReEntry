function xo_p1 = Integrater_RK4(xo, uu, time, dt, func)

% Runge-Kutta 4th-Order Numerical Integration

k1 = func(xo,uu,time) * dt;
k2 = func(xo + 0.5*k1,uu, time + 0.5*dt) * dt;
k3 = func(xo + 0.5*k2,uu, time + 0.5*dt) * dt;
k4 = func(xo + k3,uu, time + dt) * dt;

xo_p1 = xo + (1/6) * (k1 + 2*k2 + 2*k3 + k4); % xo_p1 = xo + 1 
