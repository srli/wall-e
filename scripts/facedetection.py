#!/usr/bin/python
 
#----------------------------------------------------------------------------
# Face Detection Test (OpenCV)
#
# thanks to:
# http://japskua.wordpress.com/2010/08/04/detecting-eyes-with-python-opencv
#----------------------------------------------------------------------------
 
import cv
import time
import Image
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
import sys
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


#HAAR_CASCADE_PATH = "/usr/local/Cellar/opencv/2.4.8.2/share/OpenCV/"
HAAR_CASCADE_PATH = "/opt/ros/hydro/share/OpenCV/"
 
class Face:
    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.midx = x + w/2
        self.midy = y + h/2 

def DetectFace(image, faceCascade):
 
    min_size = (20,20)
    image_scale = 2
    haar_scale = 1.1
    min_neighbors = 3
    haar_flags = 0
 
    # Allocate the temporary images
    grayscale = cv.CreateImage((image.width, image.height), 8, 1)
    smallImage = cv.CreateImage(
            (
                cv.Round(image.width / image_scale),
                cv.Round(image.height / image_scale)
            ), 8 ,1)
 
    # Convert color input image to grayscale
    cv.CvtColor(image, grayscale, cv.CV_BGR2GRAY)
 
    # Scale input image for faster processing
    cv.Resize(grayscale, smallImage, cv.CV_INTER_LINEAR)
 
    # Equalize the histogram
    cv.EqualizeHist(smallImage, smallImage)
 
    # Detect the faces
    faces = cv.HaarDetectObjects(
            smallImage, faceCascade, cv.CreateMemStorage(0),
            haar_scale, min_neighbors, haar_flags, min_size
        )
 
    # If faces are found
    faceObjects = []

    if faces:

        for ((x, y, w, h), n) in faces:
            faceObjects.append(Face(x,y,w,h))
            # the input to cv.HaarDetectObjects was resized, so scale the
            # bounding box of each face and convert it to two CvPoints
            pt1 = (int(x * image_scale), int(y * image_scale))
            pt2 = (int((x + w) * image_scale), int((y + h) * image_scale))
            cv.Rectangle(image, pt1, pt2, cv.RGB(0, 100, 255), 5, 8, 0)
 
    return [image,faceObjects]

def callback(data):
    global image
    source = CvBridge().imgmsg_to_cv2(data, desired_encoding="bgr8")
    image = cv.CreateImageHeader((source.shape[1], source.shape[0]), cv.IPL_DEPTH_8U, 3)
    cv.SetData(image, source.tostring(), 
               source.dtype.itemsize * 3 * source.shape[1])

def publisher():
    global image
    rospy.init_node("face_location",anonymous = True)
    rospy.Subscriber("/camera/rgb/image_color", Image, callback)

     
    #faceCascade = cv.Load("haarcascades/haarcascade_frontalface_default.xml")
    #faceCascade = cv.Load("haarcascades/haarcascade_frontalface_alt2.xml")
    faceCascade = cv.Load(HAAR_CASCADE_PATH + "haarcascades/haarcascade_frontalface_alt.xml")
    #faceCascade = cv.Load("haarcascades/haarcascade_frontalface_alt_tree.xml")
    pub = rospy.Publisher('face_location', String)
    while not rospy.is_shutdown():
        while (cv.WaitKey(15)==-1):
            img = image
            if type(img) == int:
                print "no data yet"
                continue;
            else:
                if not img:
                    print "No camera"
                [image,faces] = DetectFace(img, faceCascade)
                faces.sort(key=lambda face: face.y)
                if len(faces) != 0:
                    face = faces[0]        
                    print "top face at:" + str(face.midx) + ", "+ str(face.midy)
                    pub.publish(str(face.midx)+","+str(face.midy))
                cv.ShowImage("face detection test", image)

if __name__ == "__main__":
    image=0 
    publisher()