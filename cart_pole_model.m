% cart_pole_model: 根据特定参数表实现的物理模型
% 包含转动惯量 (Jp), 旋转阻尼 (d), 和小车摩擦 (b)
%
function [thetaNext,thetaDotNext,thetaacc,xNext,xDotNext] = cart_pole_model(force,theta,thetaDot,x,xDot)

% ---------------------------------------------------------------
% 1. 来自参数表的物理参数 / Physical Parameters from Datasheet
% ---------------------------------------------------------------
% l = 0.2;             % 摆杆质心距离 [m] / Distance to pole's center of mass
% m = 0.1528;          % 摆杆质量 [kg] / Mass of the pole
% M = 0.6;             % 小车质量 [kg] / Mass of the cart
% Jp = 0.0000814971;   % 摆杆绕质心的转动惯量 [kg*m^2] / Moment of inertia of the pole
% g = 9.81;            % 重力加速度 [m/s^2] / Gravity acceleration
% d = 0.001968;        % 旋转轴摩擦阻尼 [Nms/rad] / Rotational damping (friction at the joint)
% b = 0.000765;        % 小车轨道摩擦系数 [Ns/m] / Cart viscous friction (on the track)
% TAU = 0.02;          % 采样周期 [s] / Sampling time step (Control frequency = 50Hz)
l  = 0.2125;   % Lp = 0.425/2
m  = 0.1679;   % Mp
M  = 0.4719;   % Mc
Jp = 0.01;     % Jp
g  = 9.81;
d  = 0.024;    % Bp，旋转阻尼
b  = 0.5;      % 估计值，后面真机微调
TAU = 0.02;

% ---------------------------------------------------------------
% 2. 求解运动方程 / Solving Equations of Motion
% ---------------------------------------------------------------
% 预计算中间变量，提高运算效率 / Pre-compute common terms for efficiency
ml = m * l;
ml2 = m * l^2;
M_plus_m = M + m;
cos_th = cos(theta);
sin_th = sin(theta);

% M(q) 质量矩阵 / Mass Matrix: 描述了系统的惯性特性
% 该矩阵是对称的正定矩阵
M_matrix = [ M_plus_m,   ml*cos_th;
             ml*cos_th,  (Jp + ml2) ];
         
% F 向量 / Force & Torque Vector: 包含外力、阻尼、重力和科氏力
% 这里的 force 是电机给小车的推力
F_vector = [ force - b*xDot + ml*thetaDot^2*sin_th;
             -d*thetaDot + m*g*l*sin_th ];

% 求解加速度 / Calculate Accelerations: [x_acc; theta_acc]
% 利用矩阵左除 (\) 求解线性方程组，比直接求逆矩阵更稳定
acc_vector = M_matrix \ F_vector;
xacc = acc_vector(1);       % 小车水平加速度
thetaacc = acc_vector(2);   % 摆杆角加速度

% ---------------------------------------------------------------
% 3. 使用欧拉法更新状态 / State Update using Euler Method
% ---------------------------------------------------------------
xNext = x + TAU * xDot;            % 下一时刻位置 / Next position
xDotNext = xDot + TAU * xacc;      % 下一时刻速度 / Next velocity
thetaNext = theta + TAU * thetaDot;% 下一时刻角度 / Next angle
thetaDotNext = thetaDot + TAU * thetaacc; % 下一时刻角速度 / Next angular velocity

return;
