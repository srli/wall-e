/* switch statement with serial input
Uses ROSserial to commuicate
load only onto one arduino
*/

#include <VarSpeedServo.h>
#include <ros.h>
#include <std_msgs/Char.h>
#include <std_msgs/String.h>
ros::NodeHandle nh; //init rosNode 

std_msgs::String str_msg; //create string msgs
ros::Publisher emotionState("emotionState", &str_msg); //declare publisher

VarSpeedServo rEye;
VarSpeedServo lEye;
VarSpeedServo huh;

int pos = 0;    // variable to store the servo position 
char inByte;    //init inByte

//init all the strings to be published in the state machine
//strings are not stored inside a message instance; instead an unsigned char is stored
//so when publishing, you must store the string data elsewhere and set the pointer
//this is what we're doing below.
char happy[6]    = "happy";
char sad[4]      = "sad";
char whoa[5]     = "whoa";
char near[]   = "too close!!";
char waiting[]  = "waiting";

void emotion_cb(const std_msgs::Char& cmd_msg){ //ROS callback funct
  	 //state machine that responds to char recieved as long as 
  	 //robot does not see a human in front of it
    switch(cmd_msg.data){
    case 72: //'h' = 72
      str_msg.data = happy;
      rEye.write(105,40,false);
      lEye.write(69,40,false);
      huh.write(90,35,true);
      break;
    case 77: // 'm' = 77
      str_msg.data = sad;
      rEye.write(92,15,false);
      lEye.write(86,15,false);
      huh.write(90,10,true);
      break;
    case 78: // 'n' = 78
      str_msg.data = whoa;
      rEye.write(130,25,false);
      lEye.write(53,25,true);
      break;
    default:
      str_msg.data = waiting;
      rEye.write(105,45,false); 
      lEye.write(69,45,false);
      huh.write(54,25,true); 
    }
  }


ros::Subscriber<std_msgs::Char> sub("emotionComm", emotion_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(emotionState);

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
  emotionState.publish(&str_msg);
  delay(1000);
  
}
