/* switch statement with serial input
 Open serial monitor and send i,k,j,l to move the robot.
 Can't use Servo.h and VarSpeedServo.h at the same time.
 */
#include <VarSpeedServo.h>

VarSpeedServo rEye;
VarSpeedServo lEye;
VarSpeedServo huh;
VarSpeedServo drive;
VarSpeedServo turn;

int pos = 0;    // variable to store the servo position 

void setup(){
  Serial.begin(9600); //setup serial comms
  drive.attach(5);  // attaches the RC signal on pin 5 to S1 
  turn.attach(6);  // attaches the RC signal on pin 6 to S2 
  drive.write(90,100,false);
  turn.write(90,100,false);
  rEye.attach(2);
  rEye.write(105,40,false); //set init pos at slow speed, running in background
  lEye.attach(3);
  lEye.write(86,40,false); //set init pos at slow speed, running in background.
  huh.attach(4);
  huh.write(90,40,true);
  huh.write(120,15,true); //set init pos at slow speed, wait until done.
  delay(1000);
  huh.write(68,15,true);
}

void loop(){
  if (Serial.available() > 0){
    int inByte = Serial.read();
    //state machine that responds to char recieved
    //single quotes tell controller to get ASCII value
    //eg. 'a'=97
    switch(inByte){
    case 'h':
      rEye.write(105,40,false);
      lEye.write(69,40,false);
      huh.write(90,35,true);
      Serial.println("happy");
      break;
    case 'm':
      rEye.write(92,15,false);
      lEye.write(86,15,false);
      huh.write(90,10,true);
      Serial.println("sad");
      break;
    case 'n':
      rEye.write(130,25,false);
      lEye.write(53,25,true);
      Serial.println("whoa");
      break;
    case 'i':
      Serial.println("forwards");
      drive.write(120,75,true);
      turn.write(90,75, true);
      break;
    case 'j':
      Serial.println("left");
      turn.write(120,50,true);
      break;
    case 'l':
      Serial.println("right");
      turn.write(35,45, true);
      break;
    case 'k':
      Serial.print("stop");
      turn.write(90);
      drive.write(90);
      break;
    default:
      Serial.println("waiting");
      //turn.writeMicroseconds(1500);
      drive.write(90);
      rEye.write(105,45,false); 
      lEye.write(69,45,false);
      huh.write(54,25,true); 
      
    }
  }
}

