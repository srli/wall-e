//On Roboclaw set to mode 2, option 4 
//RC MIXED MODE

#include <Servo.h> 
 
Servo drive;  // create servo object to control Drive (S1)
Servo turn;  // create servo object to control Turns (S2)
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  drive.attach(5);  // attaches the RC signal on pin 5 to S1 
  turn.attach(6);  // attaches the RC signal on pin 6 to S2 
} 
 
 
void loop() 
{ 
  myservo1.writeMicroseconds(1500);  //stop
  myservo2.writeMicroseconds(1500);  //full reverse
  delay(2000);
  //myservo1.writeMicroseconds(1400);  //full reverse
  //myservo2.writeMicroseconds(1350);  //full forward
  //delay(5000);
} 