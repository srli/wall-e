#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Char
from walle.msg import *

def callback(data):
	global message, prev_pos
	xposition = int(data.positionx)
	print xposition
	if xposition > 20:
		message = 74
	if xposition < -20:
		message = 76
	else:
		message = 75
	if prev_pos == xposition:
		message = 75
	prev_pos = xposition
	return

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
	message = 75	
	prev_pos = 0
   	publisher()