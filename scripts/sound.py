#!/usr/bin/env python

"""
Adapted code from Olin College OccamLab
Github repo found here: https://github.com/occamLab/eye-helper-cv
"""
import roslib; roslib.load_manifest('walle')
import rospy
from std_msgs.msg import String
from std_msgs.msg import Char
from walle.msg import *
import random

import subprocess
import time

class audio_object:
    def __init__(self, name):
        self.name = name
        self.path = "../media" # TODO: fix this so it doesn't use '..'
        self.filename = "{}/{}.mp3".format(self.path, self.name)
        self.player = 'mplayer'
        self.playme = False

    
    def play_wave(self):
        """
        plays an inputted wav file
        """
        print self.filename
        cmd = '{} {}'.format(self.player, self.filename)
        popen = subprocess.Popen(cmd, shell=True)
        popen.communicate()
    
    def update(self):
        while True:
            time.sleep(0.5)
            if self.playme:
                print "playing sound file ", self.filename
                self.play_wave()
                self.playme = False

def sound_callback(data):
    global all_sounds
    global all_sounds_list

    char = data.data
    print char
    if char == 8:
        print "play huh"
        all_sounds["huh"].playme = True
    elif char == 9:
        print "play whistle"
        all_sounds["whistle"].playme = True
    elif char == 10:
        print "play yoohoo"
        all_sounds["yoohoo"].playme = True
    elif char == 11:
        print "play ooh"
        all_sounds["ooh"].playme = True

    for sound in all_sounds_list:
        sound.update()

def subscriber():
    rospy.init_node("sound_node", anonymous = True)
    rospy.Subscriber("/emotion", Char, sound_callback) #subscribing to detected gestures from detectfinger
    # r = rospy.Rate(10)
    # while not rospy.is_shutdown():
    #     r.sleep()
 
if __name__ == '__main__':
    huh = audio_object("huh")
    whistle = audio_object("whistle")
    yoohoo = audio_object("yoohoo")
    ooh = audio_object("ooh")

    all_sounds = {"huh":huh, "whistle":whistle, "yoohoo":yoohoo, "ooh":ooh}
    all_sounds_list = [huh, whistle, yoohoo, ooh]

    # huh.playme = True

    # huh.update()
    while not rospy.is_shutdown():
        subscriber()