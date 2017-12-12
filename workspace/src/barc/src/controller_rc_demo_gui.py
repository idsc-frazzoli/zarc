#!/usr/bin/env python

# ---------------------------------------------------------------------------
# Licensing Information: You are free to use or extend these projects for
# education or reserach purposes provided that (1) you retain this notice
# and (2) you provide clear attribution to UC Berkeley, including a link
# to http://barc-project.com
#
# Attibution Information: The barc project ROS code-base was developed at UC
# Berkeley in the Model Predictive Control (MPC) lab by Jon Gonzales
# (jon.gonzales@berkeley.edu) and Greg Marcil (grmarcil@berkeley.edu). The cloud
# services integation with ROS was developed by Kiet Lam
# (kiet.lam@berkeley.edu). The web-server app Dator was based on an open source
# project by Bruce Wootton
# ---------------------------------------------------------------------------

# README: This node serves as an outgoing messaging bus from odroid to arduino
# Subscribes: steering and motor commands on 'ecu'
# Publishes: combined ecu commands as 'ecu_pwm'

from rospy import init_node, Subscriber, Publisher, get_param
from rospy import Rate, is_shutdown, ROSInterruptException, spin, on_shutdown
from barc.msg import ECU
from barc.msg import RC_inputs
from node_example.msg import GUI_inputs

from numpy import pi
import rospy

def rc_inputs_callback(data):
    global rc_throttle, rc_steering, flag
    rc_throttle = data.motor
    rc_steering = data.servo
    flag = data.control_flag

def gui_inputs_callback(data):
    global gui_throttle, gui_steering
    gui_throttle = data.motor
    gui_steering = data.servo

def main_auto():
    global rc_throttle, rc_steering, flag, gui_throttle, gui_steering

    # initialize the ROS node
    init_node('manual_control', anonymous=True)
    Subscriber('rc_inputs', RC_inputs, rc_inputs_callback)
    Subscriber('gui_inputs', GUI_inputs, gui_inputs_callback)
    nh = Publisher('ecu_pwm', ECU, queue_size = 10)

    # set node rate
    rateHz = 50
    dt = 1.0/rateHz
    rate = Rate(rateHz)

    rc_throttle = 90
    rc_steering = 90
    gui_throttle = 90
    gui_steering = 90
    flag = False
	

    # main loop
    while not is_shutdown():
        # want gui control
        if flag is False:
            ecu_cmd = ECU(gui_throttle, gui_steering)
            nh.publish(ecu_cmd)
            rate.sleep()
        # want to override with rc control
        else: 
            ecu_cmd = ECU(rc_throttle, rc_steering)
            nh.publish(ecu_cmd)
            rate.sleep()

#############################################################
if __name__ == '__main__':
    try:
        main_auto()
    except ROSInterruptException:
        pass
