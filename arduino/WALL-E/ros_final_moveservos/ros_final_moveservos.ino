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
VarSpeedServo rarm;
VarSpeedServo larm;

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
char helloSequence[] = "hi!";
char goodbyeSequence[] = "bye!";
char rogerThat[] = "got it!";

void emotion_cb(const std_msgs::Char& cmd_msg){ //ROS callback funct
  	 //state machine that responds to char recieved as long as 
  	 //robot does not see a human in front of it
    switch(cmd_msg.data){
    case 6: 
      str_msg.data = whoa;
      rEye.write(130,25,false); //r eye parallel to ground
      lEye.write(53,25,true); //l eye parallel to ground
      rarm.write(15,100,false); //r arm out
      larm.write(165,100,true); //l arm out
      delay(500); //wait 1/4 sec
      rEye.write(105,40,false); //go back to neutral
      lEye.write(69,40,false);
      rarm.write(120,100,true);//R arm in
      larm.write(68, 100, true);//in
      break;
    case 7: 
      str_msg.data = sad;
      rEye.write(92,15,false);
      lEye.write(86,15,false);
      huh.write(90,10,true);
      //back to neutral
      delay(500);
      break;
    case 8:
      str_msg.data = happy;
      rEye.write(105,40,false);
      lEye.write(69,40,false);
      huh.write(90,35,true);
      break;
    case 9: //arbitrary value
      Serial.print("r wave");
      rarm.write(15,100,true);//R arm out
      rarm.write(120,100,true);//R arm in
      rarm.write(15,100,true); //R arm out
      rarm.write(120,100,true);//R arm in
      break;
    case 10: //arbitrary value
      Serial.print("l wave");
      larm.write(165, 100, true);//L arm out
      larm.write(68, 100, true);//in
      larm.write(165,100, true);//out
      larm.write(68, 100, true);//in
      break;
    case 11:
      Serial.print("both wave");
      larm.write(165, 80, false);//l arm out
      rarm.write(15,80,true); //r arm out
      larm.write(68, 80, false);//L arm in
      rarm.write(120,80,true);//R arm in
      larm.write(165,80, false);//l arm out
      rarm.write(15,80,true); //r arm out
      larm.write(68, 80, false);//L arm in
      rarm.write(120,80,true);//R arm in
      break;
    case 12:
      Serial.print("parallel wave");
      larm.write(165, 80, false);//l arm out
      rarm.write(120,80,true);//R arm in
      larm.write(68, 80, false);//L arm in
      rarm.write(15,80,true); //r arm out
      larm.write(165, 80, false);//l arm out
      rarm.write(120,80,true);//R arm in
      larm.write(68, 80, false);//L arm in
      rarm.write(15,80,true); //r arm out
      rarm.write(120,80,true);//R arm in
      break;
    case 13: 
      str_msg.data = helloSequence;
      rEye.write(105,40,false);
      lEye.write(69,40,false);
      huh.write(90,35,true);
      rEye.write(130,25,false);
      lEye.write(53,25,true);
      rEye.write(105,40,false);
      lEye.write(69,40,false);
      larm.write(165, 80, false);//l arm out
      rarm.write(15,80,true); //r arm out
      larm.write(68, 80, false);//L arm in
      rarm.write(120,80,true);//R arm in
      larm.write(165,80, false);//l arm out
      rarm.write(15,80,true); //r arm out
      larm.write(68, 80, false);//L arm in
      rarm.write(120,80,true);//R arm in 
      break;
    case 14:
      str_msg.data = goodbyeSequence;
      rEye.write(92,15,false); //sad eyes
      lEye.write(86,15,false);
      rarm.write(15,100,true);//wave R arm////R arm out
      rarm.write(120,100,true);//R arm in
      rarm.write(15,100,true); //R arm out
      rarm.write(120,100,true);//R arm in
      delay(250);
      rEye.write(105,40,false); //go back to neutral
      lEye.write(69,40,false);
      break;
    case 15: 
    str_msg.data = rogerThat;
      rEye.write(130,25,false); //r eye parallel to ground
      lEye.write(53,25,true); //l eye parallel to ground
      rarm.write(15,100,false); //r arm out
      larm.write(165,100,true); //l arm out
      delay(250); //wait 1/4 sec
      rEye.write(105,40,false); //go back to neutral
      lEye.write(69,40,false);
    default:
      str_msg.data = waiting;
      rEye.write(105,45,false); 
      lEye.write(69,45,false);
      huh.write(54,25,true); 

    }
  }


ros::Subscriber<std_msgs::Char> sub("emotion", emotion_cb);

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

  rarm.attach(7);
  larm.attach(8);
  rarm.write(130,40,false);
  larm.write(80, 40, false);
}

void loop(){
  nh.spinOnce();
  emotionState.publish(&str_msg);
  delay(1000);
  
}
