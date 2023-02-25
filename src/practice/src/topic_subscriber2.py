#! /usr/bin/env python3

import rospy    #ROSに必要な基本的な機能を読み込む
import rospkg

from ar_track_alvar_msgs.msg import AlvarMarkers #トピックに送るメッセージの定義を読み込む

from visualization_msgs.msg import Marker



#from geometry_msgs.msg import PoseStamped pose


#AA = AlvarMarkers()
#print(type(AA.header.frame_id))


def callback(msg):
    """ callback関数：購読するときに実行させる関数

        引数にmsgとあるが，関数を指定するときは特に引数を渡すことはない．
        自動的に購読対象を引数とする．

    """
    AA = AlvarMarkers()
    print(msg)

def callback2(msg):
    print('hello')
    """ callback関数：購読するときに実行させる関数

        引数にmsgとあるが，関数を指定するときは特に引数を渡すことはない．
        自動的に購読対象を引数とする．

    """
    BB = Marker()
    print(msg.id)
    if msg.id == 0:
        print("0???") 
    else:
        print("ALL_ID")


rospy.init_node('topic_subscriber') #'topic_subscriber'という名前でノードを新規作成（初期化）

#sub  = rospy.Subscriber('ar_pose_marker', AlvarMarkers, callback)  #'counter', Int32のトピックを購読し，実行させる関数をcallbackに設定
sub2 = rospy.Subscriber('visualization_marker', Marker, callback2)

rospy.spin()    #継続して処理をさせる．while not is_shutdown()のショートカットといえる
