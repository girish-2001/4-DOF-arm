//program for calibration
#include<Servo.h>
//initializing objects for every servo motor
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

int ang_base=0;
int ang_shoulder=0;
int ang_elbow=0;
int ang_wrist=0;
int ang_gripper=0;

String s1="";
String s2="";
String s3="";
String s4="";
String s5="";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.begin(9600);  
base.attach(9);
shoulder.attach(10);
elbow.attach(11);
wrist.attach(5);
gripper.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0);
s1=Serial.readStringUntil('/');
s2=Serial.readStringUntil('/');
s3=Serial.readStringUntil('/');                          
s4=Serial.readStringUntil('/');
s5=Serial.readStringUntil('/');

ang_base= s1.toInt();
ang_shoulder= s2.toInt();
ang_elbow= s3.toInt();
ang_wrist= s4.toInt();  
ang_gripper=s5.toInt();

base.write(ang_base);
delay(1000);
shoulder.write(ang_shoulder);
delay(1000);
elbow.write(ang_elbow);
delay(1000);
wrist.write(ang_wrist);
delay(1000);
gripper.write(ang_gripper);
delay(1000);
}
