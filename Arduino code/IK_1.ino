//Program for inverse kinematics of the arm. Some values
//can be changed according to the requirements

#include<Servo.h>
//initializing objects for every servo motor
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

int ang_base=90;
int ang_shoulder=90;
int ang_elbow=0;
int ang_wrist=0;


int diff1=0;
int diff2=0;
int diff3=0;
int diff4=0;
//defining variables for the current angle-to be changed according to the requirements
int b=90;//0-180-base angle
int s=90;//0-150-shoulder
int e= 0;//0-180-elbow
int w=0;//0-180-wrist
int g=0;

//defining variables for target angles
int b_f=90;//0-180-base angle
int s_f=90;//0-150-shoulder
int e_f=0;//0-180-elbow
int w_f=0;//0-180-wrist
int g_f=0;

String s1="";
String s2="";
String s3="";
String s4="";

void setup()
{
//attaching the servo motors.
//base-  9, A0
//shoulder- 10, A1
//elbow-11, A2
//wrist- 5, A3
//gripper-6, A4
  
Serial.begin(9600);  
base.attach(9);
shoulder.attach(10);
elbow.attach(11);
wrist.attach(5);
gripper.attach(6);

//setting initial angles for each servo
base.write(90);

shoulder.write(90);

elbow.write(0);
wrist.write(0);
gripper.write(0);
}

void loop()
{
//getting angles as input
while(Serial.available()==0);
s1=Serial.readStringUntil('/');
s2=Serial.readStringUntil('/');
s3=Serial.readStringUntil('/');                          
s4=Serial.readStringUntil('/');

//converting string to Integer
b_f= s1.toInt();
s_f= s2.toInt();
e_f= s3.toInt();
w_f= s4.toInt();  
  
//displaying angles on serial monitor  
Serial.println(b_f);
Serial.println(s_f);
Serial.println(e_f);
Serial.println(w_f);
  
  
  
//condition for checking arm angles
if(b_f>180 || b_f<0){
Serial.println("configuration not possible");
b_f=b;
s_f=s;
e_f=e;
w_f=w;
}

if(s_f>150 || s_f<0){
Serial.println("configuration not possible");
b_f=b;
s_f=s;
e_f=e;
w_f=w;
}
  
if(e_f>=180|| e_f<=0){
Serial.println("configuration not possible");
b_f=b;
s_f=s;
e_f=e;
w_f=w;
}

if(w_f>150 || w_f<0){
Serial.println("configuration not possible");
b_f=b;
s_f=s;
e_f=e;
w_f=w;
}
  
diff1=b_f-b;
diff2=s_f-s;
diff3=e_f-e;
diff4=w_f-w;

while(!(diff1==0 && diff2==0 && diff3==0 && diff4==0)){
if(diff1>0)
  ang_base++;
if(diff1<0)
  ang_base--;
if(diff2>0)
  ang_shoulder++;
if(diff2<0)
  ang_shoulder--;
if(diff3>0)
  ang_elbow++;
if(diff3<0)
  ang_elbow--;
if(diff4>0)
  ang_wrist++;
if(diff4<0)
  ang_wrist--;
  
diff1=b_f-ang_base;
diff2=s_f-ang_shoulder;
diff3=e_f-ang_elbow;
diff4=w_f-ang_wrist;
base.write(ang_base);
delay(10);
shoulder.write(ang_shoulder);
delay(10);
elbow.write(ang_elbow);
delay(10);

}
wrist.write(ang_wrist);
//delay(10);
b=ang_base;
s=ang_shoulder;
e=ang_elbow;
w=ang_wrist;


Serial.println(base.read(),DEC);
Serial.println(shoulder.read(),DEC);
Serial.println(elbow.read(),DEC);
Serial.println(wrist.read(),DEC); 

 

}
