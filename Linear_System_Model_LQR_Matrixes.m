clc;close all;
syms x_dot_dot x_dot x alpha_dot_dot alpha_dot alpha F
%% Constants
Mc = 0.4719;
Mp = 0.1679;
Lp = 0.425/2;
Jp = 0.01;
Beq = 30;
Bp = 0.024;
g =9.81;
Rm=2.12;
Kt=0.08505;
Kb=0.11693;
rmp=0.013745;

%%Linearised System Model

eq1_lin = (Mp+Mc)*x_dot_dot + 0 - Mp*Lp*alpha_dot_dot == F - Beq*x_dot;

eq2_lin = (Mp*Lp^2+Jp)*alpha_dot_dot - Mp*Lp*x_dot_dot - Mp*Lp*g*alpha == Bp*alpha_dot;

[x_ddot,alpha_ddot] = solve([eq1_lin,eq2_lin],[x_dot_dot,alpha_dot_dot]);

vpa(x_ddot,4)
vpa(alpha_ddot,4)

K_x = vpa(coeffs(x_ddot),4)
K_alpha = vpa(coeffs(alpha_ddot),4)

A = [0,0,1,0;
     0,0,0,1;
     0,K_x(1,3),K_x(1,1),K_x(1,2);
     0,K_alpha(1,3),K_alpha(1,1),K_alpha(1,2)]
A= double(A);
B = [0;
     0;
     K_x(1,4);
     K_alpha(1,4)]
B = double(B);
%%LQR Part
Q_mat=diag(4)
Q_mat(1,1)= 3000
Q_mat(2,2)= 5000
Q_mat(3,3)= 1
Q_mat(4,4)= 1

R_mat=2;

K=lqr(A,B,Q_mat,R_mat)
Nbar=rscale(A,B,[1 0 0 0],0,K);





