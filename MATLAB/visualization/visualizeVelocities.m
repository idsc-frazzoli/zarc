%vextract velocities

str = '/home/jelavice/pwm_90,93/viconExampleOutput_23-11-2017 03:06:10.csv';
data = csvread(str,1);
file = fopen(str,'r');
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

d1 = designfilt('lowpassiir','FilterOrder',12, ...
    'HalfPowerFrequency',0.15,'DesignMethod','butter');

%filter the data

yaw_f = filtfilt(d1,yaw);
dxB_f = filtfilt(d1,dxB);
dyB_f = filtfilt(d1,dyB);
d2 = designfilt('lowpassiir','FilterOrder',12, ...
    'HalfPowerFrequency',0.05,'DesignMethod','butter');
r_f = filtfilt(d2,r);



subplot(3,1,1)
plot(t,yaw,'Linewidth', 2);
ylabel('heading');
hold on
subplot(3,1,2)
plot(t(1:end-1),dxB_f,'Linewidth', 2);
hold on
plot(t(1:end-1),dyB_f,'Linewidth', 2);
legend('V_x', 'V_y')
subplot(3,1,3)
plot(t(1:end-1), r_f);
ylabel('yaw rate')
hold on

figure
subplot(3,1,1)
plot(t,yaw,'Linewidth', 2);
hold on
plot(t,yaw_f,'Linewidth', 2);
subplot(3,1,2)
plot(t(1:end-1),dxB,'Linewidth', 2);
hold on
plot(t(1:end-1),dyB,'Linewidth', 2);
plot(t(1:end-1),dxB_f,'Linewidth', 2);
grid on
plot(t(1:end-1),dyB_f,'Linewidth', 2);
legend('V_x', 'V_y')
subplot(3,1,3)
plot(t(1:end-1), r);
hold on
plot(t(1:end-1), r_f);
