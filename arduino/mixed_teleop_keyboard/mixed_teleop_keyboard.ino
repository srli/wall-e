/* switch statement with serial input
Open serial monitor and send i,k,j,l to move the robot.
*/
#include <Servo.h>
Servo drive;  // create servo object to control Drive (S1)
Servo turn;  // create servo object to control Turns (S2)
 
int pos = 0;    // variable to store the servo position 

void setup(){
  Serial.begin(9600); //setup serial comms
  drive.attach(5);  // attaches the RC signal on pin 5 to S1 
  turn.attach(6);  // attaches the RC signal on pin 6 to S2 
  drive.writeMicroseconds(1500);
  turn.writeMicroseconds(1500);
}

void loop(){
  if (Serial.available() > 0){
    int inByte = Serial.read();
    //state machine that responds to char recieved
    //single quotes tell controller to get ASCII value
    //eg. 'a'=97
    switch(inByte){
    case 'i':
      Serial.println("forwards");
      drive.writeMicroseconds(1350);
      turn.writeMicroseconds(1500);
      break;
    case 'j':
      Serial.println("left");
      turn.writeMicroseconds(1350);
      break;
    case 'l':
      Serial.println("right");
      turn.writeMicroseconds(1585);
      break;
    case 'k':
      Serial.print("stop");
      turn.writeMicroseconds(1500);
      drive.writeMicroseconds(1500);
      break;
    default:
      Serial.println("waiting");
      //turn.writeMicroseconds(1500);
      drive.writeMicroseconds(1500);
      break;
    }
  }
}
