#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Example Python node to publish on a specific topic.
"""

# Import required Python code.
import rospy

# Give ourselves the ability to run a dynamic reconfigure server.
from dynamic_reconfigure.server import Server as DynamicReconfigureServer

# Import custom message data and dynamic reconfigure variables.
from zarc_gui.msg import GUI_inputs
from zarc_gui.cfg import zarcGUIConfig as ConfigType


class NodeExample(object):
    '''
    Node example class.
    '''
    def __init__(self):
        # Get the private namespace parameters from the parameter server:
        # set from either command line or launch file.
        self.rate = rospy.get_param('~rate', 20.0)
        rospy.loginfo('rate = %f', self.rate)
        # Create a dynamic reconfigure server.
        self.server = DynamicReconfigureServer(ConfigType, self.reconfigure_cb)
        # Create a publisher for our custom message.
        self.pub = rospy.Publisher('gui_inputs', GUI_inputs, queue_size=10)
        # Initialize message variables.
        self.enable = rospy.get_param('~enable', False)
        self.int_motor = rospy.get_param('~motor', 90)
        self.int_servo = rospy.get_param('~servo', 90)
        self.T = 5
        self.t = 0

        # Create a timer to go to a callback at a specified interval.
        rospy.Timer(rospy.Duration(1 / self.rate), self.timer_cb)

        # Allow ROS to go to all callbacks.
        rospy.spin()

    def timer_cb(self, _event):
        """
        Called at a specified interval. Publishes message.
        """
        if not self.enable:
            # reset msg to "90" when enable unselected
            msg = GUI_inputs()
            msg.motor = 90
            msg.servo = 90
            self.pub.publish(msg)
            self.t = 0
            return
        else:
            self.t = self.t + 1/self.rate

        # Set the message type to publish as our custom message.
        msg = GUI_inputs()
        # Assign message fields to values from the parameter server.
        msg.motor = rospy.get_param('~motor', self.int_motor)
        #msg.servo = rospy.get_param('~servo', self.int_servo)
        msg.servo = -30/self.T * self.t + 90
        if msg.servo < 0:
            msg.servo = 0
        #print msg.servo


        # Fill in custom
        # message variables with values updated from dynamic
        # reconfigure server.
        self.int_motor = msg.motor
        self.int_servo = msg.servo

        # Publish our custom message.
        self.pub.publish(msg)

    def reconfigure_cb(self, config, dummy):
        '''
        Create a callback function for the dynamic reconfigure server.
        '''
        # Fill in local variables with values received from dynamic reconfigure
        # clients (typically the GUI).
        self.enable = config["enable"]
        # reset GUI to "90" when enable is unselected
        if not self.enable:
            config["motor"] = 90
            config["servo"] = 90
        self.int_motor = config["motor"]
        self.int_servo = config["servo"]
        # Return the new variables.
        return config

# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('ECU_command')
    # Go to class functions that do all the heavy lifting. Do error checking.
    try:
        NodeExample()
    except rospy.ROSInterruptException:
        pass
