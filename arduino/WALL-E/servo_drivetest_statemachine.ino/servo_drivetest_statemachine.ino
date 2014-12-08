/* switch statement with serial input
 Open serial monitor and send i,k,j,l to move the robot.
 Can't use Servo.h and VarSpeedServo.h at the same time.
 */
#include <Servo.h>
#include <BMSerial.h>
#include <RoboClaw.h>

Servo rEye;
Servo lEye;
Servo huh;

int pos = 0;    // variable to store the servo position 
int ultrasonicsensorPin = A0;
int sensorValue = 0;

//Roboclaw Address (128)
#define address 0x80

//Setup communcaitions with roboclaw. Use pins 10 and 11 with 10ms timeout
RoboClaw roboclaw(A6,A7,10000);

void setup(){
  Serial.begin(9600); //setup serial comms with PC
  Serial.println("init comms");
  //have arduino communicate at 2400 baud
  roboclaw.begin(2400);
  roboclaw.ForwardMixed(address,0);
  roboclaw.TurnLeftMixed(address,0);
  roboclaw.TurnRightMixed(address,0);

  rEye.attach(2);
  rEye.write(105); //set init pos at slow speed, running in background
  lEye.attach(3);
  lEye.write(86); //set init pos at slow speed, running in background.
  huh.attach(4);
  huh.write(90);
  delay(50);
  huh.write(120); //set init pos at slow speed, wait until done.
  delay(1000);
  huh.write(68);
}


void loop(){
  sensorValue = analogRead(ultrasonicsensorPin);
  //Serial.println(sensorValue);

  if (Serial.available() > 0 && sensorValue >70){
    int inByte = Serial.read();
    //state machine that responds to char recieved
    //single quotes tell controller to get ASCII value
    //eg. 'a'=97
    switch(inByte){
    case 'h':
      Serial.println("happy");
      rEye.write(105);
      lEye.write(69);
      huh.write(90);
      break;
    case 'm':
      Serial.println("sad");
      rEye.write(92);//,15,false);
      lEye.write(86);//,15,false);
      huh.write(90);//,10,true);
      break;
    case 'n':
      Serial.println("whoa");
      rEye.write(130);//,25,false);
      lEye.write(53);//,25,true);
      break;
    case 'i':
      Serial.println("forward");
      roboclaw.ForwardMixed(address,20);
      break;
    case 'j':
      Serial.println("left");
      roboclaw.TurnRightMixed(address,20);
      break;
    case 'l':
      Serial.println("right");
      roboclaw.TurnLeftMixed(address,20);
      break;
    case 'k':
      Serial.print("stop");
      roboclaw.ForwardMixed(address,0);
      delay(50);
      roboclaw.TurnRightMixed(address,0);
      delay(50);
      roboclaw.TurnLeftMixed(address,0);
      break;
    default:
      Serial.println("waiting");
      roboclaw.ForwardMixed(address,0);
      delay(50);
      roboclaw.TurnRightMixed(address,0);
      delay(50);
      roboclaw.TurnLeftMixed(address,0);
      rEye.write(105);//,45,false);
      lEye.write(69);//,45,false);
      huh.write(54);//,25,true); 

      }
    }
  else
  {
  roboclaw.ForwardMixed(address,0);
  delay(50);
  roboclaw.TurnRightMixed(address,0);
  delay(50);
  roboclaw.TurnLeftMixed(address,0);
  }

}




