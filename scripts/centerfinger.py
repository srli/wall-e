#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int16
from walle.msg import *


def callback(data):
	global message
	xposition = int(data.positions)
	print xposition
	if xposition > 20:
		message = 74
		return
	if xposition < -20:
		message = 76
		return
	else:
		message = 75

def publisher():
    rospy.init_node("centerfinger", anonymous = True)
    rospy.Subscriber("/point_location", pointerpos, callback)
    pub = rospy.Publisher('/motors', Int16)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
 		msg = message
 		pub.publish(msg)
 		r.sleep()
       
if __name__ == "__main__":
	message = 75
   	publisher()