WALL-E
================

Code repository for WALL-E project.

-Runs off of OpenNI, not OpenNI2, so make sure to install correct version
-Requires drivers from the drivers folder to be installed. Follow readme directions

Launching:

rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 unique_nodename

(emotion arduino = black cable)
(motors arduino = white cable)

roslaunch openni_launch openni.launch
navigate to source folder
rosrun walle detectfinger
rosrun walle centerfinger.py
rosrun walle emotions.py
