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
from numpy import pi
import rospy

def rc_inputs_callback(data):
    global throttle, steering, flag
    throttle = data.motor
    steering = data.servo
    flag = data.control_flag

def main_auto():
    global throttle, steering, flag

    # initialize the ROS node
    init_node('manual_control', anonymous=True)
    Subscriber('rc_inputs', RC_inputs, rc_inputs_callback)
    nh = Publisher('ecu_pwm', ECU, queue_size = 10)

    # set node rate
    rateHz = 50
    dt = 1.0/rateHz
    rate = Rate(rateHz)

    throttle = 90
    steering = 90
    flag = False
	

    # main loop
    while not is_shutdown():
        if flag is False:
            ecu_cmd = ECU(throttle, steering)
            nh.publish(ecu_cmd)
            rate.sleep()
<<<<<<< HEAD
        else: 
            throttle = 105
            steering = 120
            ecu_cmd = ECU(throttle, steering)
            nh.publish(ecu_cmd)
            rate.sleep()
=======
        else:
            throttle = 110
            steering = 110
            ecu_cmd = (throttle,steering)
            nh.publish(ecu_cmd)
            rate.sleep()

>>>>>>> 906cda95ea43b38ab767ba7f4bab351124d647fe

#############################################################
if __name__ == '__main__':
    try:
        main_auto()
    except ROSInterruptException:
        pass
