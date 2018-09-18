#! /usr/bin/env python
# coding: utf-8

import rospy
from amada_forcegauge.msg import ForceGaugeData
from forcegauge import ForceGauge
import time
import sys

class ForceGaugePublisher:
    """
    DS2-500Nの出力をパブリッシュするクラス 
    """

    def __init__( self, topicname, serialport, baudrate = 19200, timeout = 0.01, nodename = "ForceGauge"):
        """
        コンストラクタ

        引数
            topicname: パブリッシュする際のトピック名
            serialport: DS2-500Nのデバイスファイルまでのパス
            baudrate: シリアル通信のボーレート (デフォルト: 19200)
            timeout: シリアル通信のタイムアウト (デフォルト: 0.01秒)
            nodename: ノードの名前 (デフォルト: ForceGauge)
        """
        self.forcegauge = ForceGauge( serialport, baudrate=baudrate, timeout=timeout)

        rospy.init_node( nodename )
        self.publisher = rospy.Publisher( topicname, ForceGaugeData, queue_size=10 )

    def __del__( self):
        """
        """
        #self.forcegauge.__del__()
        del self.forcegauge

    def publish(self):
        """
        publish 処理
        """
        publishdata = ForceGaugeData()
        publishdata.data = self.forcegauge.read()
        publishdata.header.stamp = rospy.Time.now()
        self.publisher.publish(publishdata)
