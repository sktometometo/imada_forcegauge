#! /usr/bin/env python
# coding: utf-8

"""
Amada の フォースゲージのドライバとなるクラス
"""

import serial
import time
import sys

from forcegauge import ForceGauge

if __name__=="__main__":

    if len( sys.argv ) != 2:
        print("print force gauge data")
        print("usage:program <serial port>")
        sys.exit(1)

    a = ForceGauge( sys.argv[1] )

    try:
        while True:
            print( str(a.read()) )
            time.sleep(0.1)
    except KeyboardInterrupt:
        del a
