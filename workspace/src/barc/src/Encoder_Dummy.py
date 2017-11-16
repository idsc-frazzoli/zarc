#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from barc.msg import Encoder


def talker():
    pub = rospy.Publisher('encoder', Encoder, queue_size=10)
    rospy.init_node('Encoder_Dummy', anonymous=True)
    rate = rospy.Rate(10)  # 10hz
    msg = Encoder()
    msg.FL = 0
    msg.FR = 0
    msg.BL = 0
    msg.BR = 0

    while not rospy.is_shutdown():
        #rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()
        msg.FL += 1
        msg.FR += 1
        msg.BL += 1
        msg.BR += 1


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
