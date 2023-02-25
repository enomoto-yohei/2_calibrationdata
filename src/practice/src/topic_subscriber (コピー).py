#! /usr/bin/env python3

import rospy    #ROSに必要な基本的な機能を読み込む
import rospkg

from ar_track_alvar_msgs.msg import AlvarMarkers #トピックに送るメッセージの定義を読み込む


def callback(msg):
    """ callback関数：購読するときに実行させる関数

        引数にmsgとあるが，関数を指定するときは特に引数を渡すことはない．
        自動的に購読対象を引数とする．

    """
    print(msg) #購読したメッセージのdataという変数に格納されているものを表示


rospy.init_node('topic_subscriber') #'topic_subscriber'という名前でノードを新規作成（初期化）


sub = rospy.Subscriber('ar_pose_marker', AlvarMarkers, callback)  #'counter', Int32のトピックを購読し，実行させる関数をcallbackに設定

rospy.spin()    #継続して処理をさせる．while not is_shutdown()のショートカットといえる
