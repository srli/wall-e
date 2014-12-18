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
	if xposition > 50:
		print "greater than 50"
		message = 1
	elif xposition < -50:
		print "less than 50"
		message = 3
	else:
		message = 5	
	
	if prev_pos == xposition:
		message = 2
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