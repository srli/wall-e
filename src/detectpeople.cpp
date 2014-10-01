#include <walle/HRI.h>
#include <sensor_msgs/Image.h>
#include <ros/ros.h>
#include <iostream>

//static int highestnum = 0;

void cameracallback(const sensor_msgs::Image &msg){
	

//int highestnum
	for(i = 0; i < msg.size(); i++){
		if i > highestnum:
			highestnum = msg[i];
	}

}

int main(int argc, char **argv)
{
    ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "detect_people", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();

  ros::Subscriber subcommand = rosnode.subscribe("/camera/rgb/image_color", 10, cameracallback);
  printf("subscribe get\n");
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
  
  if highestnum > 1:
  	printf("Hello!\n");

  //printf("Press enter to send message\n");
  //getchar();

  
  for (;;)
    ros::spinOnce();

  return 0;
}
