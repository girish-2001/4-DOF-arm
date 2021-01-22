function[Th_1, Th_2,Th_3,Th_4]=IK(x,y,z)
%This function implements inverse kinematics
%x,y,z are given as inputs
L_1=12;
L_2=12.5;
L_3=7.5;
L_4=5;
L(1)= Link([0 L_1 0 pi/2]);
L(2)= Link([0 0 L_2 0]);
L(3)= Link([0 0 L_3 0]);
L(4)= Link([0 0 L_4 0]);

Robot= SerialLink(L);
Robot.name = "4 DOF";
T=[1 0 0 x;
   0 1 0 y;
   0 0 1 z;
   0 0 0 1];
J= Robot.ikine(T,[0,0,0],'mask',[1,1,1,0,0,0])*180/pi;
Th_1=J(1);
Th_2=J(2);
Th_3=J(3);
Th_4=J(4)+90;
%Robot.plot([Th_1,Th_2,Th_3,Th_4]);
%Robot.teach();
end
