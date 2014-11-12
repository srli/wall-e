#include <walle/HRI.h>
#include <sensor_msgs/Image.h>
#include <ros/ros.h>
#include <iostream>
#include <stdlib.h>

/*#include "opencv2\opencv.hpp"
#include "opencv2\highgui\highgui.hpp" 
#include "opencv2\imgproc\imgproc.hpp" 
*/
static int highestnum = 0;

#define SAMPLE_XML_FILE "Data/Sample-Tracking.xml"
#define SAMPLE_XML_FILE_LOCAL "Sample-Tracking.xml"

void cameracallback(const sensor_msgs::Image &msg){
	printf("hello\n");
  //std::cout << msg.height << std::endl;
/*  int current_highest = 0;
	for(int i = 0; i < msg.height; i++){
    for(int j = 0; j < msg.width; j++){
		  if (msg.data(j, i) > current_highest){
			 current_highest = msg.data(j, i);
      }
    }
	}

  highestnum = current_highest;*/

}

bool fileExists(const char *fn)
{
  bool exists;
  xnOSDoesFileExist(fn, &exists);
  return exists;
}


int main(int argc, char **argv)
{
    ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "detect_people", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();
  //ros::Subscriber subcommand = rosnode.subscribe("/camera/rgb/image_color", 10, cameracallback);



  ros::Subscriber subcommand = rosnode.subscribe("/camera/depth_registered/image_raw", 10, cameracallback);
  printf("subscribe get\n");
  
  if      (fileExists(SAMPLE_XML_FILE)) printf("SAMPLE_XML_FILE");
    else if (fileExists(SAMPLE_XML_FILE_LOCAL)) printf("SAMPLE_XML_FILE_LOCAL");
    else {
      printf("Could not find '%s' nor '%s'. Aborting.\n" , SAMPLE_XML_FILE, SAMPLE_XML_FILE_LOCAL);
    }

  /*ros::Time last_ros_time_;
  bool wait = true;
  while (wait) {
    printf("waiting!\n");
    last_ros_time_ = ros::Time::now();
    if (last_ros_time_.toSec() > 0) {
      wait = false;
    }
  }
*/
  //ros::Publisher pub = rosnode.advertise<walle::HRI>("walle_say_hi", 10);
  //walle:HRI interaction;
  
  if (highestnum > 1){
  	printf("Hello!\n");
  }

  //printf("Press enter to send message\n");
  //getchar();

  
  for (;;)
    ros::spinOnce();

  return 0;
}
