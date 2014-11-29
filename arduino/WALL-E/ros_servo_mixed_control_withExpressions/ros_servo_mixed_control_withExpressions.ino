/* switch statement with serial input, responds to i,j,k,l
Uses ROSserial to commuicate
*/
//#if (ARDUINO >= 100)
// #include <Arduino.h>
//#else
// #include <WProgram.h>
//#endif

#include <VarSpeedServo.h>
#include <ros.h>
#include <std_msgs/Char.h>
#include <std_msgs/String.h>

ros::NodeHandle nh; //init rosNode 

std_msgs::String str_msg; //create string msgs
ros::Publisher driveComms("driveComms", &str_msg); //declare publisher

VarSpeedServo rEye;
VarSpeedServo lEye;
VarSpeedServo huh;
VarSpeedServo drive;
VarSpeedServo turn;
 
int pos = 0;    // variable to store the servo position 
char inByte;    //init inByte

//init all the strings to be published in the state machine
char forwards[9] = "forwards";
char waiting[8]  = "waiting";
char left[5]     = "left";
char right[6]    = "right";
char stopped[5]  = "stop";

void motor_cb(const std_msgs::Char& cmd_msg){ //ROS callback funct
  //inByte =(cmd_msg.data); //get command to put into state machine 
      //state machine that responds to char recieved
    //single quotes tell controller to get ASCII value
    //eg. 'a'=97
  switch(cmd_msg.data){
  case 72: //'h' = 72
    Serial.println("happy");
    rEye.write(105,40,false);
    lEye.write(69,40,false);
    huh.write(90,35,true);
    break;
  case 77: // 'm' = 77
    Serial.println("sad");
    rEye.write(92,15,false);
    lEye.write(86,15,false);
    huh.write(90,10,true);
    break;
  case 78: // 'n' = 78
    Serial.println("whoa");
    rEye.write(130,25,false);
    lEye.write(53,25,true);
    break;
  case 73: //val of 'i' is 73
    str_msg.data = forwards;
    drive.writeMicroseconds(1350);
    turn.writeMicroseconds(1500);
    break;
  case 74: //val of 'j' is 74
    str_msg.data = left;
    turn.writeMicroseconds(1350);
    break;
  case 76: //val of 'l' is 76
    str_msg.data = right;
    turn.writeMicroseconds(1585);
    break;
  case 75: //val of k is 75
    str_msg.data = stopped;
    turn.writeMicroseconds(1500);
    drive.writeMicroseconds(1500);
    break;
  default:
    str_msg.data = waiting;
    turn.writeMicroseconds(1500);
    drive.writeMicroseconds(1500);
    rEye.write(105,45,false); 
    lEye.write(69,45,false);
    huh.write(54,25,true); 
    
  }
}

ros::Subscriber<std_msgs::Char> sub("motor", motor_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(driveComms);
  drive.attach(5);  // Fwd/back motion controlled by pin 5 to S1 
  turn.attach(6);  // turning motion controlled by pin 6 to S2 
  drive.writeMicroseconds(1500); //initialize drive
  turn.writeMicroseconds(1500); //init turn
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
  nh.spinOnce();
  driveComms.publish(&str_msg);
  delay(1000);
  
}
