%vextract velocities


data = csvread('/home/jelavice/Vicon_exampleOutput.csv',1);
file = fopen('/home/jelavice/Vicon_exampleOutput.csv','r');
header = fgets(file);
fclose(file);
labels = getLabels(header);


for i=1:length(labels)
    str = [labels{i} '=data(:,i);'];
   eval(str); 
end

%% plot positins and velocities

N = length(t);



plot(x,y, 'Linewidth', 2);
xlabel('x');
xlabel('y');

Q = [qw qx qy qz];

eulerAngles = quat2eul(Q);
yaw = eulerAngles(:,1);

dxW = zeros(N-1,1);
dyW = zeros(N-1,1);
dxB = zeros(N-1,1);
dyB = zeros(N-1,1);
r = zeros(N-1,1);
for i=2:N
    dxW(i-1) = (x(i) - x(i-1)) / (t(i) - t(i-1));
    dyW(i-1) = (y(i) - y(i-1)) / (t(i) - t(i-1));
    r(i-1) = (yaw(i) - yaw(i-1)) / (t(i) - t(i-1));
    R = [cos(yaw(i)) -sin(yaw(i)); sin(yaw(i)) cos(yaw(i))];
    temp = R' * [dxW(i-1); dyW(i-1)];
    dxB(i-1) = temp(1);
    dyB(i-1) = temp(2);
end

subplot(3,1,1)
plot(t,yaw,'Linewidth', 2);
hold on
subplot(3,1,2)
plot(t(1:end-1),dxB,'Linewidth', 2);
hold on
plot(t(1:end-1),dyB,'Linewidth', 2);
legend('V_x', 'V_y')
subplot(3,1,3)
plot(t(1:end-1), r);
hold on

