#!/usr/bin/python
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Char
from walle.msg import *
import random

def interaction_callback(data):
	global message
	wave = data.wave 
	hello = data.hello
	goodbye = data.goodbye
	#our message fields are all booleans so we can do easy if statements
	if wave:
		print "waved!"
		message = random.randint(8, 11) #sets messages as desired as reponses to detected gestures
	if hello:
		print "hello!"
		message = 13
	if goodbye:
		print "goodbye"
		message = 14
	if not goodbye and not hello and not wave:
		print "none work"
		message = 0
	print message


def comms_callback(data):
	global message
	if "close" in data:
		message = 6


def publisher():
	global message
	rospy.init_node("interaction_node", anonymous = True)
	rospy.Subscriber("/detected_gestures", gestures, interaction_callback) #subscribing to detected gestures from detectfinger
	rospy.Subscriber("/drive_comms", String, comms_callback) #listens to feedback stream from the Arduino controlling the drive train
	pub = rospy.Publisher('/emotion', Char) #publishes to emotion node, which the Arduino controlling WALL-E's eyes and ears listen to
	r = rospy.Rate(20)
	while not rospy.is_shutdown():
		if message != 0:
			msg = message
			pub.publish(msg)
		r.sleep()
       
if __name__ == "__main__":
	print "emotions.py"
	message = 0
   	publisher()