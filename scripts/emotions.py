#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import *
from walle.msg import *

def interaction_callback(data):
	wave = data.wave
	click = data.click
	if wave:
		print "waved!"
		message = 80

def publisher():
    rospy.init_node("interaction_node", anonymous = True)
    #rospy.Subscriber("/point_location", pointerpos, callback)
    rospy.Subscriber("/detected_gestures", gestures, interaction_callback)
    pub = rospy.Publisher('/emotion', Int16)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
 		msg = message
 		pub.publish(msg)
 		r.sleep()
       
if __name__ == "__main__":
	message = 75
   	publisher()