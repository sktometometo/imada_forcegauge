#! /usr/bin/env python
# coding: utf-8

import rospy
from forcegaugepublisher import ForceGaugePublisher
import time
import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("publish force data read from imada forcegauge")
        print("usage:program <serial port> <output topic (optional, default:ForceGauge)>")
        sys.exit(0)

    if len(sys.argv) > 2:
        topicname = sys.argv[2]
    else:
        topicname = "ForceGauge"

    a = ForceGaugePublisher(topicname, sys.argv[1])

    try:
        r = rospy.Rate(100)  # 100Hz
        while not rospy.is_shutdown():
            a.publish()
            r.sleep()

    except KeyboardInterrupt:
        del a
        sys.exit(0)
