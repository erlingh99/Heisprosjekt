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
Joystick_gain_x = 5;
Joystick_gain_y = -5;


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

%Linearized system matrix
A = [0 1 0; 0 0 0; 0 0 0];                  
B = [0 0; 0 K_1; K_2 0];               

%LQR-tuning
Q = [6.485 0 0; 0 6 0; 0 0 4];            
R = [0.04 0; 0 0.04];

K = lqr(A, B, Q, R);

F = [K(1,1), K(1,3); K(2,1), K(2,3)];

