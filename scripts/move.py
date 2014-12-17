#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Char
from walle.msg import *


def callback(data):
	global message, prev_pos
	xposition = int(data.positionx) #we only care about the X position of the hand
	print xposition
	if xposition > 50: #if x to left of center, we turn left to match
		message = 1
	if xposition < -50: #if x to right of center, we turn right to match
		message = 3 
	else: #if x is += 50 of the center, we don't do anything 
		message = 5	
	if prev_pos == xposition:
		message = 5
	prev_pos = xposition
	return

def publisher():
    rospy.init_node("centerfinger", anonymous = True)
    rospy.Subscriber("/point_location", pointerpos, callback) #subscribes to XYZ node from detectfinger
    pub = rospy.Publisher('/move', Char)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
 		msg = message
 		pub.publish(msg)
 		r.sleep()
       
if __name__ == "__main__":
	print "move.py initialized!"
	message = 5
	prev_pos = 0
   	publisher()