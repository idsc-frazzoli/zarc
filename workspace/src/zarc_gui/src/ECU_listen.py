#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Example Python node to listen on a specific topic.
"""

# Import required Python code.
import rospy

# Import custom message data.
from zarc_gui.msg import GUI_inputs

def callback(data):
    '''
    Callback function for the subscriber.
    '''
    # Simply print out values in our custom message.
    rospy.loginfo(rospy.get_name() + " motor = %d, servo = %d" % (data.motor, data.servo))

def listener():
    '''
    Main function.
    '''
    # Create a subscriber with appropriate topic, custom message and name of
    # callback function.
    rospy.Subscriber('gui_inputs', GUI_inputs, callback)
    # Wait for messages on topic, go to callback function when new messages
    # arrive.
    rospy.spin()

# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('ECU_listen')
    # Go to the main loop.
    listener()
