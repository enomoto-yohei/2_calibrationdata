#! /usr/bin/env python3

import rospy # ROSに必要な基本的な機能を読み込む
import rospkg
from playsound import playsound # 音声に関するライブラリ
from ar_track_alvar_msgs.msg import AlvarMarkers #トピックに送るメッセージの定義を読み込む
from visualization_msgs.msg import Marker #トピックに送るメッセージの定義を読み込む




def sound_message(id): # 音声出力の関数

    if id==1: # IDが1の時
        playsound("/home/enomoto/2_calibrationdata/src/practice/src/sound/id_1.mp3")

    elif id==0: # IDが2の時
        playsound("/home/enomoto/2_calibrationdata/src/practice/src/sound/id_0.mp3")

    elif id==2: # IDが2の時
        playsound("/home/enomoto/2_calibrationdata/src/practice/src/sound/id_2.mp3")

    elif id==3: # IDが3の時
        playsound("/home/enomoto/2_calibrationdata/src/practice/src/sound/id_3.mp3")

    else:
        playsound("/home/enomoto/2_calibrationdata/src/practice/src/sound/else.mp3")

def callback(msg): # ARマーカに関する全ての情報


    AA = AlvarMarkers()
    print(msg)

def callback2(msg): # ARマーカの位置やIDに関する情報

    BB = Marker()
    print(msg.id)

    id = msg.id # メッセージ内のIDのみ取得
    sound_message(id) # 音声出力の関数呼び出し


rospy.init_node('topic_subscriber') # topic_subscriberという名前でノードを新規作成（初期化）

#sub  = rospy.Subscriber('ar_pose_marker', AlvarMarkers, callback)
sub2 = rospy.Subscriber('visualization_marker', Marker, callback2)

rospy.spin()
#rospy.Rate(50)
