// ros_mixed_drive.ino
//uses rosserial to send and receive messages between arduino + roboclaw and laptop running kinect

//run code with: rosrun <pkg> <python_node> _port:=/dev/ttyUSB0
//so these are all commands to drive the motors. in single command mode, 0 = stop, 127 = full
//in multicommand mode (eg. LeftRightMixed) 0 = full left, 64 = stop, and 127 = full right
	//  roboclaw.ForwardMixed(address, 64);//fwd and stopped, cmd 8
 //  	delay(2000);
 //  	roboclaw.BackwardMixed(address, 64);//backwards and stopped, cmd 9
 //  	delay(2000); 
 //  	roboclaw.TurnRightMixed(address, 64); //right and stopped, cmd 10
 //  	delay(2000);
 //  	roboclaw.TurnLeftMixed(address, 64); //left and stopped, cmd 11
 //  	delay(2000);
 //  	roboclaw.ForwardBackwardMixed(address,32);
 //  	roboclaw.ForwardBackwardMixed(address,96);
 //  	roboclaw.LeftRightMixed(address, 32);
 //  	roboclaw.LeftRightMixed(address, 96);
 //  	//stop motors
 //  	roboclaw.ForwardMixed(address,0);
 //  	delay(10000);

#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include "BMSerial.h"
#include "RoboClaw.h"

//Roboclaw Address
#define address 0x80
//Setup Comms with Roboclaw for Uno-- connect pin 5 to S1, Roboclaw on mode 7 and option 3
RoboClaw roboclaw(5,6,10000);//10ms timeout
//create node handle: creates pubs and subs and includes serial port comms
ros::NodeHandle nh; 
std_msgs::String driveCmd; //create string with name "driveCmd"
std_msgs::String driveFeedback; //driveFeedback will tell main computer what's going on
std_msgs::String enc_vals; //create string w name "enc_vals" for odom feedback
ros::Publisher enc_vals("enc_vals", &driveCmd); //created publisher w topic name "enc_vals"
ros::Publisher lowlevelstate("lowlevelstate", &driveFeedback); 
ros::Subscriber<std_msgs::Empty> sub(/cmd_vel, &drivecmd_Cb); //create subscriber w topic to subscribe to and callback function it uses

//create callback function for subscriber
void drivecmd_Cb(const std_msgs::String& driveCmd){
	cmd = driveCmd.cmd;
	if (cmd == "front"){
		driveFeedback.cmd = "arduino.drivecmd_Cb: received /driveCmd front";
		roboclaw.ForwardMixed(address, 20); 
		delay(2000);
	}
	else if (cmd == "left"){
		driveFeedback.cmd = "arduino.drivecmd_Cb: received /driveCmd left";
		roboclaw.LeftrightMixed(address, 54);
		delay(2000);
	}
	else if (cmd == "right"){
		driveFeedback.cmd = "arduino.drivecmd_Cb: received /driveCmd right";
		roboclaw.LeftrightMixed(address, 74);
		delay(2000);
	}
	else{
		driveFeedback.cmd = "arduino.drivecmd_Cb: received /driveCmd other";
		roboclaw.ForwardMixed(address, 0);//stop if nobody 
		delay(2000);
	}
}

//in setup you also subscribe to topics you wish to listen to
void setup() {
  roboclaw.begin(19200); //set roboclaw baud rate = 38400baud
  nh.initNode(); //init ros node handle
  nh.advertise(enc_vals); //advertise topics being published
  nh.subscribe(sub) //subscribe to topics to listen to
}

void loop() {
  driveCmd.data = hello;
  enc_vals.publish(&driveCmd);
  nh.spinOnce();
  delay(1000); //wait 1000ms
  //check if drive command is forwards and distance to human is greater than 1 m
  
}

