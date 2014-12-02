#!/usr/bin/env python

#CompRobo Final Project, Adela Wee and Sophie Li
#Python code to drive WALL-E

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist, Vector3
#from sensor_msgs.msg import kinect

def drive_robot(command):
	"""takes command and publishes motor twist message to robot"""
	pub = rospy.Publisher('cmd_vel',Twist,queue_size=10)
	#sub = rospy.Subscirber('kinect')
	rospy.init_node('teleop',anonymous=True)
	r = rospy.Rate(10) #run code at 10Hz

	# place state machine here?
	if command == "forward":
		velocity_msg = Twist(Vector3((0.1),0.0,0.0), Vector3(0.0,0.0,0.0))
		print("moving forwards")
	elif command == "left":
		velocity_msg = Twist(Vector3(0.0,0.0,0.0),Vector3(0.0,0.0,-0.1))
		print("moving left")
	elif command == "right":
		velocity_msg = Twist(Vector3(0.0,0.0,0.0),Vector3(0.0,0.0,0.1))
		print("moving right")
	else: #don't move
		velocity_msg = velocity_msg = Twist(Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0))
		print("waiting for next command")
	pub.publish(velocity_msg)

if __name__ == '__main__':
		rospy.init_node('teleop', anonymous =True)
		while not rospy.is_shutdown():
			drive_robot()
