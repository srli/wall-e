//Arduino Mega and Leonardo chips only support some pins for receiving data back from the RoboClaw
//This is because only some pins of these boards support PCINT interrupts or are UART receivers.
//Mega: 0,10,11,12,13,14,15,17,19,50,51,52,53,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15
//Leonardo: 0,8,9,10,11

//Arduino Due currently does not support SoftwareSerial. Only hardware uarts can be used, pins 0/1, 14/15, 16/17 or 18/19.

//Things required to use Roboclaw library
#include <BMSerial.h>
#include <RoboClaw.h>

//Roboclaw Address
#define address 0x80

//Setup communcaitions with roboclaw. Use pins 10 and 11 with 10ms timeout
RoboClaw roboclaw(5,6,10000);

void setup() {
  Serial.begin(9600); //serial connection to PC
  Serial.println("init comms");
  //Communciate with roboclaw at 38400bps
  roboclaw.begin(2400);
  roboclaw.ForwardMixed(address,0);
  roboclaw.TurnLeftMixed(address,0);
  roboclaw.TurnRightMixed(address,0);
}

void loop() {
  if (Serial.available() > 0){
    int inByte = Serial.read();
    switch(inByte){
      case 'i':
        Serial.println("forward");
        roboclaw.ForwardMixed(address,20);
        //roboclaw.write(128, 8, 32, ((128+8+32) & 0x7F));
        break;
      case 'j':
        Serial.println("left");
        roboclaw.TurnRightMixed(address,20);
        //roboclaw.LeftRightMixed(address,80); //64-127 is turn left
        //roboclaw.write(128, 11, 32, ((128+11+32) & 0x7F)); 
        break;
      case 'l':
        Serial.println("right");
        roboclaw.TurnLeftMixed(address,20);
        
        //roboclaw.LeftRightMixed(address, 50); //less than 64 = turn right
        //roboclaw.write(128, 10, 32, ((128+10+32) & 0x7F1)); 
        break;
      default:
        Serial.println("stop");
         roboclaw.ForwardMixed(address,0);
         delay(50);
         roboclaw.TurnRightMixed(address,0);
         delay(50);
         roboclaw.TurnLeftMixed(address,0);
         //roboclaw.LeftRightMixed(address,1);
          // roboclaw.write(128,8,0,((128+8+0) & 0x7F));
          // roboclaw.write(128,13,0,((128+13+0) & 0x7F));
    }
    
  }

}
