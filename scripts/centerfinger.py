#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Char
from walle.msg import *


def callback(data):
	global message
	xposition = int(data.positionx)
	print xposition
	if xposition > 20:
		message = 1
		return
	if xposition < -20:
		message = 3
		return
	else:
		message = 5

def publisher():
    rospy.init_node("centerfinger", anonymous = True)
    rospy.Subscriber("/point_location", pointerpos, callback)
    pub = rospy.Publisher('/move', Char)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
 		msg = message
 		pub.publish(msg)
 		r.sleep()
       
if __name__ == "__main__":
	message = 5
   	publisher()