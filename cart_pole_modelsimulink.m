function [thetaNext,thetaDotNext,thetaacc,xNext,xDotNext] = cart_pole_modelsimulink(force,theta,thetaDot,x,xDot)

% 原厂参数
l   = 0.2125;    % Lp = 0.425/2
m   = 0.1679;    % Mp
M   = 0.4719;    % Mc
Jp  = 0.01;
g   = 9.81;
d   = 0.024;     % Bp
b   = 30;        % Beq（线性化模型里直接用）
TAU = 0.004;     % 控制周期4ms（原厂250Hz）


% Kt  = 0.08505;
% rmp = 0.013745;
% Rm  = 2.12;
% Vm  = force / 4095 * 12;  % PWM转电压
% F   = Kt * Vm / rmp;       % 电压转力

% PWM→电压→力的换算 (补充了电机内阻 Rm)
Kt  = 0.08505;
rmp = 0.013745;
Rm  = 2.12;
Vm  = force / 4095 * 12;           % PWM转电压
F   = (Kt * Vm) / (Rm * rmp);      % 【修正】电压转推力：必须除以 Rm

ml  = m * l;
ml2 = m * l^2;
M_plus_m = M + m;
cos_th = cos(theta);
sin_th = sin(theta);

M_matrix = [ M_plus_m,   ml*cos_th;
             ml*cos_th,  (Jp + ml2) ];

F_vector = [ F - b*xDot + ml*thetaDot^2*sin_th;
             -d*thetaDot + m*g*l*sin_th ];

acc_vector = M_matrix \ F_vector;
xacc     = acc_vector(1);
thetaacc = acc_vector(2);

xNext        = x     + TAU * xDot;
xDotNext     = xDot  + TAU * xacc;
thetaNext    = theta + TAU * thetaDot;
thetaDotNext = thetaDot + TAU * thetaacc;
return;