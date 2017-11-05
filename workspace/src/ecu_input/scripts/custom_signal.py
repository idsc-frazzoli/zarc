#!/usr/bin/env python
import rospy
from ecu_input.msg import ECU

def signal():
    pub = rospy.Publisher('custom_output', ECU) #name of topic = custom_output
    rospy.init_node('custom_pwm', anonymous=True) #name of node = custom_pwm
    r = rospy.Rate(10) #10hz
    msg = ECU()
    msg.motor = 90
    msg.servo = 90

    while not rospy.is_shutdown():
        rospy.loginfo(msg)
        pub.publish(msg)
        r.sleep()

if __name__ == '__main__':
    try:
        signal()
    except rospy.ROSInterruptException: pass
