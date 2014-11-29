/* switch statement with serial input, responds to i,j,k,l
Uses ROSserial to commuicate
*/
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>

ros::NodeHandle nh; //init rosNode 

std_msgs::String str_msg; //create string msgs
ros::Publisher driveComms("driveComms", &str_msg); //declare publisher

Servo drive;  // create servo object to control Drive (S1)
Servo turn;  // create servo object to control Turns (S2)
 
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
    //turn.writeMicroseconds(1500);
    drive.writeMicroseconds(1500);
    break;
  }
}

ros::Subscriber<std_msgs::Char> sub("motor", motor_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(driveComms);
  drive.attach(5);  // attaches the RC signal on pin 5 to S1 
  turn.attach(6);  // attaches the RC signal on pin 6 to S2 
  drive.writeMicroseconds(1500);
  turn.writeMicroseconds(1500);
}

void loop(){
  nh.spinOnce();
  driveComms.publish(&str_msg);
  delay(1000);
  
}
