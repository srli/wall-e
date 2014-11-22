/* switch statement with serial input
Open serial monitor and send i,k,j,l to move the robot.
*/

void setup(){
  Serial.begin(9600); //setup serial comms
}

void loop(){
  if (Serial.available() > 0){
    int inByte = Serial.read();
    //state machine that responds to char recieved
    //single quotes tell controller to get ASCII value
    //eg. 'a'=97
    switch(inByte){
    case 'i':
      Serial.println("forwards")
      break;
    case 'k':
      Serial.print("stop")
      default:
      Serial.println("waiting")

    }
  }
}