#! /usr/bin/env python
# coding: utf-8

"""
Amada の フォースゲージのドライバとなるクラス
"""

import serial
import time
import sys

class ForceGauge(object):
    """
    DS2-500N を扱うクラス
    """

    def __init__( self, serialport, baudrate = 19200, timeout = 0.01):
        """
        コンストラクタ

        引数
            serialport : シリアルデバイスへのパス
            baudrate   : シリアル通信のボーレート (bps)
            timeout    : タイムアウト (秒)
        """
        self.serialport = serialport
        self.baudrate = baudrate
        self.serdev = serial.Serial( serialport, baudrate = baudrate, timeout = timeout)

    def __del__( self ):
        """
        デストラクタ
        """
        self.serdev.close()

    def read(self):
        """
        フォースゲージの値を読み込む
        """
        self.serdev.write(b"D\r")
        string = self.serdev.read(10)
        try:
            return float(string[:-4])
        except ValueError:
            return 0

