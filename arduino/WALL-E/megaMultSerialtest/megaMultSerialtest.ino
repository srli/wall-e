/*
  Mega multple serial test
 
 Receives from the main serial port, sends to the others. 
 Receives from serial port 1, sends to the main serial (Serial 0).
 
 This example works only on the Arduino Mega
 
 The circuit: 
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:
 
 created 30 Dec. 2008
 by Tom Igoe
 
 This example code is in the public domain.
 
 */


void setup() {
  // initialize both serial ports:
  Serial.begin(9600);//computer
  Serial1.begin(9600); //arduino to roboserial
}

void loop() {
  // // read from port 1, send to port 0:
  // if (Serial1.available()) {
  //   //int inByte = Serial1.read();
  //   Serial.write(inByte); 
  if (Serial.available() > 0){
    int inByte = Serial.read();
    switch(inByte){
      case 'i':
        Serial.println("forward");
        //roboclaw.ForwardMixed(address,20);
        Serial1.write("[128, 8, 32, 1]");
        break;
      // case 'j':
      //   Serial.println("left");
      //   //roboclaw.TurnRightMixed(address,20);
      //   //roboclaw.LeftRightMixed(address,80); //64-127 is turn left
      //   Serial1.write("128, 11, 32, 1"); 
      //   break;
      // case 'l':
      //   Serial.println("right");
      //   //roboclaw.TurnLeftMixed(address,20);
        
      //   //roboclaw.LeftRightMixed(address, 50); //less than 64 = turn right
      //   Serial1.write("128, 10, 32, ((128+10+32) & 0x7F1)"); 
      //   break;
      default:
        Serial.println("stop");
         // roboclaw.ForwardMixed(address,0);
         // delay(50);
         // roboclaw.TurnRightMixed(address,0);
         // delay(50);
         // roboclaw.TurnLeftMixed(address,0);
         //roboclaw.LeftRightMixed(address,1);
          Serial1.write("128,8,0,((128+8+0) & 0x7F)");
          Serial1.write("128,13,0,((128+13+0) & 0x7F)");
  }
}
}
