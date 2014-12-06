#!/usr/bin/env python  
import roslib; roslib.load_manifest('walle')
from walle.msg import *
import roslib
import rospy
import sys

from math import *
import random
from std_msgs.msg import String
from sensor_msgs.msg import Image
import cv2
from cv2 import cv
from cv_bridge import CvBridge, CvBridgeError

class image_converter:
	def __init__(self):
		self.image_pub = rospy.Publisher("cv_converted", Image)
		cv2.namedWindow("Frame", 1)
		self.bridge = CvBridge()
		self.pointlocation_sub = rospy.Subscriber("/point_location", pointerpos, self.pointupdate)
		self.image_sub = rospy.Subscriber("/camera/rgb/image_color", Image, self.callback)
		self.point_location = ((0,0))

	def pointupdate(self, data):
		print "hello"
		# xy = data.positions
		# self.point_location[0] = xy[0]
		# self.point_location[1] = xy[1]

	def callback(self, data):
		try:
			cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
		except CvBridgeError, e:
			print e

		#cv2.circle(cv_image, (self.point_location), 5, 255)
		cv2.imshow("Frame", cv_image)
		cv2.waitKey(3)

		try:
			self.image_pub.publish(self.bridge.cv2_to_imgmsg(cv_image, 'bgr8'))
		except CvBridgeError, e:
			print e

def main(args):
	ic = image_converter()
	rospy.init_node('image_converter', anonymous=True)
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print "Shutting down"
	cv2.destroyAllWindows()


# def view_frame(data):
# 	''' captures frame from webcame, creates thresholded and gaussian blur images '''
# 	ret, frame = cap.read()
# 	cimg = frame

# 	cv2.imshow("threshed", cimg)
# 	c = cv2.waitKey(1)

# #return gaussian_images


if __name__ == "__main__":
	main(sys.argv)