%visualize velocities





N = length(t);
dx = zeros(N-1,1);
for i=2:N
dx(i-1) = (x(i) - x(i-1)) / (t(i) - t(i-1));
dy(i-1) = (y(i) - y(i-1)) / (t(i) - t(i-1));
end
plot(t,sqrt(dx.^2 + dy.^2))
plot(t(1:N-1),sqrt(dx.^2 + dy.^2))