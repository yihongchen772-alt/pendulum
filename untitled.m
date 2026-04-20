% LQR控制律：u = -K*x
% 当theta=0.1rad时，LQR输出力是多少？
K = [-38.73, 164.21, -76.34, 41.06];
state = [0; 0.1; 0; 0];  % x=0m, theta=0.1rad
u = -K * state