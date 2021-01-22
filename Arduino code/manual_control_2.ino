//Program for manual control of the arm. Some values
//can be changed according to the requirements

#include<Servo.h>
//initializing objects for every servo motor
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

//defining variables for the angles
int ang_base=90;
int ang_shoulder=90;
int ang_elbow= 90;
int ang_wrist=90;
int ang_gripper=0;
char input;

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
delay(200);
shoulder.write(90);
delay(200);
elbow.write(90);
delay(200);
wrist.write(90);
delay(200);
gripper.write(90);
}

void loop()
{
//Reading the values from the potentiometer
while(Serial.available()==0);
input= Serial.read();
if(input=='B')
ang_base++;
else if(input=='A')
ang_base--;
else if(input=='C')
ang_shoulder--;
else if(input=='D')
ang_shoulder++;
 if(input=='E')
ang_elbow--;
else if(input=='F')
ang_elbow++;
else if(input=='G')
ang_wrist--;
else if(input=='H')
ang_wrist++;
else if(input=='I')
ang_gripper++;
else if(input=='J')
ang_gripper--;
Serial.println(Serial.read());

base.write(ang_base);
delay(5);
shoulder.write(ang_shoulder);
delay(5);
elbow.write(ang_elbow);
delay(5);
wrist.write(ang_wrist);
delay(5);
gripper.write(ang_gripper);
delay(5);
}
