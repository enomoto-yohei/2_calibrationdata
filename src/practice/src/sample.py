#! /usr/bin/env python3

import rospy    #ROSに必要な基本的な機能を読み込む
import rospkg

from sensor_msgs.msg import Image #トピックに送るメッセージの定義を読み込む

#from visualization_msgs.msg import Marker



#from geometry_msgs.msg import PoseStamped pose


#AA = AlvarMarkers()
#print(type(AA.header.frame_id))


def callback(msg):
    print('hello')
    """ callback関数：購読するときに実行させる関数

        引数にmsgとあるが，関数を指定するときは特に引数を渡すことはない．
        自動的に購読対象を引数とする．

    """
    #print(msg) #購読したメッセージのdataという変数に格納されているものを表示
    #AA = AlvarMarkers()
    print(msg)
    #BB = Marker()
    #print(BB)


rospy.init_node('topic_subscriber') #'topic_subscriber'という名前でノードを新規作成（初期化）
print('wow')

sub  = rospy.Subscriber('/uvc_camera/image_raw', Image, callback)  #'counter', Int32のトピックを購読し，実行させる関数をcallbackに設定
#sub2 = rospy.Subscriber('ar_pose_marker', Marker, callback) 



rospy.spin()    #継続して処理をさせる．while not is_shutdown()のショートカットといえる
