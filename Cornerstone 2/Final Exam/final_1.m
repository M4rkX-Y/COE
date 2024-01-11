x = 0:.2:3.6;
v0 = input('The initial velocity in m/s: ');
a0 = input('The initial angle in degrees: ');
[y] = traj_calc(x, v0, a0)

[y1] = traj_calc(x,6,42.5);
[y2] = traj_calc(x,10,45);

tiledlayout(2,1);

nexttile;
plot(x, y1);
title('Trajactory of object with 6m/s initial velocity and 42.5 degree initial angle');
xlabel('x');
ylabel('y');

nexttile;
plot(x,y2);
title('Trajactory of object with 10m/s initial velocity and 45 degree initial angle');
xlabel('x');
ylabel('y');

%%
function [y] = traj_calc(x, v0, a0)
    y = x*tand(a0)+((-9.81)*x.^2)/(2*(v0^2)*cosd(a0));
end