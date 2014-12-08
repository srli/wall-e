/* switch statement with serial input, responds to i,j,k,l
Uses ROSserial to commuicate
*/
//#if (ARDUINO >= 100)
// #include <Arduino.h>
//#else
// #include <WProgram.h>
//#endif

//#include <VarSpeedServo.h>
#include <BMSerial.h>
#include <RoboClaw.h>
#include <ros.h>
#include <std_msgs/Char.h>
#include <std_msgs/String.h>

//Roboclaw Address (128)
#define address 0x80

//Setup communcaitions with roboclaw. Use pins 10 and 11 with 10ms timeout
RoboClaw roboclaw(10,11,10000);


ros::NodeHandle nh; //init rosNode 

std_msgs::String str_msg; //create string msgs
ros::Publisher driveComms("driveComms", &str_msg); //declare publisher

//VarSpeedServo rEye;
//VarSpeedServo lEye;
//VarSpeedServo huh;

 
int pos = 0;    // variable to store the servo position 
char inByte;    //init inByte
int ultrasonicsensorPin = A0;
int sensorValue = 0;



//init all the strings to be published in the state machine
//strings are not stored inside a message instance; instead an unsigned char is stored
//so when publishing, you must store the string data elsewhere and set the pointer
//this is what we're doing below.
char forwards[] = "forwards";
char waiting[]  = "waiting";
char left[5]     = "left";
char right[6]    = "right";
char stopped[5]  = "stop";
char happy[6]    = "happy";
char sad[4]      = "sad";
char whoa[5]     = "whoa";
char near[]   = "too close!!";

void motor_cb(const std_msgs::Char& cmd_msg){ //ROS callback funct
  sensorValue = analogRead(ultrasonicsensorPin); //init ultrasonic
  if (sensorValue >70){

        //state machine that responds to char recieved
      //single quotes tell controller to get ASCII value
      //eg. 'a'=97
    switch(cmd_msg.data){
    // case 72: //'h' = 72
    //   str_msg.data = happy;
    //   rEye.write(105,40,false);
    //   lEye.write(69,40,false);
    //   huh.write(90,35,true);
    //   break;
    // case 77: // 'm' = 77
    //   str_msg.data = sad;
    //   rEye.write(92,15,false);
    //   lEye.write(86,15,false);
    //   huh.write(90,10,true);
    //   break;
    // case 78: // 'n' = 78
    //   str_msg.data = whoa;
    //   rEye.write(130,25,false);
    //   lEye.write(53,25,true);
    //   break;
    case 73: //val of 'i' is 73
      str_msg.data = forwards;
      roboclaw.ForwardMixed(address,30);
      break;
    case 74: //val of 'j' is 74
      str_msg.data = left;
      roboclaw.TurnRightMixed(address,23);
      break;
    case 76: //val of 'l' is 76
      str_msg.data = right;
      roboclaw.TurnLeftMixed(address,23);
      break;
    case 75: //val of k is 75
      str_msg.data = stopped;
      roboclaw.ForwardMixed(address,0);
      delay(50);
      roboclaw.TurnRightMixed(address,0);
      delay(50);
      roboclaw.TurnLeftMixed(address,0);
      break;
    default:
      str_msg.data = waiting;
      roboclaw.ForwardMixed(address,0);
      delay(50);
      roboclaw.TurnRightMixed(address,0);
      delay(50);
      roboclaw.TurnLeftMixed(address,0);
      // rEye.write(105,45,false); 
      // lEye.write(69,45,false);
      // huh.write(54,25,true); 
    }
  }
  else{
  str_msg.data = near;
  roboclaw.ForwardMixed(address,0);
  delay(50);
  roboclaw.TurnRightMixed(address,0);
  delay(50);
  roboclaw.TurnLeftMixed(address,0);
  }
}

ros::Subscriber<std_msgs::Char> sub("motor", motor_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(driveComms);

  roboclaw.begin(2400);
  roboclaw.ForwardMixed(address,0);
  roboclaw.TurnLeftMixed(address,0);
  roboclaw.TurnRightMixed(address,0);


  // rEye.attach(2);
  // rEye.write(105,40,false); //set init pos at slow speed, running in background
  // lEye.attach(3);
  // lEye.write(86,40,false); //set init pos at slow speed, running in background.
  // huh.attach(4);
  // huh.write(90,40,true);
  // huh.write(120,15,true); //set init pos at slow speed, wait until done.
  // delay(1000);
  // huh.write(68,15,true);
}

void loop(){
  nh.spinOnce();
  driveComms.publish(&str_msg);
  delay(1000);
  
}
