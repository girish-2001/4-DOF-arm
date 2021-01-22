function [x,y,z]=FK(Th_1,Th_2,Th_3,Th_4)
%This function implements forward kinematics
%Angles are given as inputs
L_1=5;
L_2=12;
L_3=8;
L_4=5;
L(1)= Link([0 L_1 0 pi/2]);
L(2)= Link([0 0 L_2 0]);
L(3)= Link([0 0 L_3 0]);
L(4)= Link([0 0 L_4 0]);

Robot= SerialLink(L);
Robot.name = "4 DOF";
Robot.plot([Th_1, Th_2 ,Th_3, Th_4]);
T= Robot.fkine([Th_1 Th_2 Th_3 Th_4]);
coordinates= transl(T);
Robot.teach();
x=coordinates(1);
y=coordinates(2);
z=coordinates(3);
end