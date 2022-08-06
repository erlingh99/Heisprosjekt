% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]
J_p = 2*m_p*l_p^2;                          %Inertia p
J_e = m_c*l_c^2 + 2*m_p*l_h^2;              %Inertia e
J_lambda = m_c*l_c^2 + 2*m_p*(l_h^2+l_p^2); %Inertia lambda

vs_0 = 7.4;                                 %voltage needed to lift elevation horizontal, experimental

K_f = (2*m_p*l_h*g - m_c*l_c*g)/(l_h*vs_0); %Motorconstant, found by K_f = -L2/(lh*vs0)
L_1 = K_f*l_p;                              
L_2 = m_c*l_c*g-2*m_p*l_h*g;
L_3 = K_f*l_h;
L_4 = K_f*l_h;

K_1 = L_1/J_p;
K_2 = L_3/J_e;
K_3 = L_4*vs_0/J_lambda;

%Linearized system matricies

%LQR
A_reg = [0 1 0 0 0;0 0 0 0 0;0 0 0 0 0;1 0 0 0 0;0 0 1 0 0];                  
B_reg = [0 0; 0 K_1; K_2 0;0 0;0 0];  

%Lunenberg observer
A_est = [0 1 0 0 0;0 0 0 0 0;0 0 0 1 0;0 0 0 0 0;K_3 0 0 0 0];                  
B_est = [0 0; 0 K_1; 0 0; K_2 0;0 0];               
C = eye(5);% minimal [0 0 1 0 0;0 0 0 0 1];


%kalman
A_kalman = [0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K_3 0 0 0 0 0];
B_kalman = [0 0;0 K_1;0 0;K_2 0;0 0; 0 0];
C_kalman = eye(6);

%Kalman with estimation of p_bias
A_observ = [0 1 0 0 0 0 0;0 0 0 0 0 0 0;0 0 0 1 0 0 0;0 0 0 0 0 0 0;0 0 0 0 0 1 0;K_3 0 0 0 0 0 0;0 0 0 0 0 0 0];
B_observ = [0 0;0 K_1;0 0;K_2 0;0 0; 0 0;0 0];
C_observ = [1 0 0 0 0 0 1;0 1 0 0 0 0 0;0 0 1 0 0 0 0;0 0 0 1 0 0 0; 0 0 0 0 1 0 0; 0 0 0 0 0 1 0];
%minimal [1 0 0 0 0 0 1;0 0 1 0 0 0 0; 0 0 0 0 1 0 0];

%rank(obsv(A_observ, C_observ)) %fully observable. e_bias is not
%rank(ctrb(A_observ, B_observ))

%Discretization
T_s = 0.002;
[A_d,B_d] = c2d(A_kalman,B_kalman,T_s);
C_d = C_kalman;

%LQR-tuning
Q = [6.485 0 0 0 0; 0 6 0 0 0; 0 0 4 0 0;0 0 0 5 0; 0 0 0 0 2];            
R = [0.04 0; 0 0.04];

%Kalman-tuning
Q_d = diag([1e-5 1e-5 1e-5 1e-5 1e-5 1e-5]);

Q_a = diag([0.01 0.01 0.01 0.01 0.01 0.01]);
H = [A_kalman Q_a;zeros(6, 6) -A_kalman'];
M = expm(H*T_s);
Q_vl = M(1:6,7:12)*M(1:6,1:6)';

R_d_stille = [1.10384587123084e-06,-1.16207908054691e-07,2.72032783667388e-07,-1.08614417867512e-07,0,-2.09565985037156e-10;-1.16207908054691e-07,7.82917904778999e-07,-2.95717656769276e-07,6.02139620329588e-08,0,-2.74553306276994e-07;2.72032783667388e-07,-2.95717656769276e-07,3.85259854841341e-06,5.51207560966765e-07,0,3.55207588515025e-07;-1.08614417867512e-07,6.02139620329588e-08,5.51207560966765e-07,3.36886887455916e-06,0,2.12408905241764e-07;0,0,0,0,0,0;-2.09565985037156e-10,-2.74553306276994e-07,3.55207588515025e-07,2.12408905241764e-07,0,8.94360505868944e-07];
R_d_drive = [0.00147927209305007,0.000231538235795237,0.00294793331031030,-0.00121913989740227,5.44408351820512e-05,1.40651716897892e-06;0.000231538235795237,0.00256433001649051,0.000699327629497674,0.00262424107565141,-3.13503442546672e-05,0.000421974441812797;0.00294793331031030,0.000699327629497674,0.0107910904147101,-0.00175294068055106,-1.58261274086619e-05,0.000262833727744328;-0.00121913989740227,0.00262424107565141,-0.00175294068055106,0.00943375880136097,-9.60184227425584e-05,0.000524837203854007;5.44408351820512e-05,-3.13503442546672e-05,-1.58261274086619e-05,-9.60184227425584e-05,1.77803756968392e-05,-6.95391493899459e-06;1.40651716897892e-06,0.000421974441812797,0.000262833727744328,0.000524837203854007,-6.95391493899459e-06,0.000181162935969899];
R_d = R_d_drive;

% Init first values
x_0 = [0 0 -pi/5 0 0 0]';
P_0 = Q_d;%diag([0.05,0.05,0.05,0.05,0.05,0.05]);
%Lqr
K = lqr(A_reg, B_reg, Q, R);
F = [K(1,1), K(1,3); K(2,1), K(2,3)];

%IMU
PORT = 3;


