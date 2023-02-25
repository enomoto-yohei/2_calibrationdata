#include <geometry_msgs/PointStamped.h>
#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include <tf2_msgs/TFMessage.h>


int main(int argc, char **argv){
    tf::Quaternion quat;//入力値tf2_msgs/TFMessage
    double r,p,y;//出力値
    tf::Matrix3x3(quat).getRPY(r, p, y);//クォータニオン→オイラー角
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh;
    ROS_INFO("(r:%f,p:%f,y:%f)",r,p,y);
    ROS_INFO("");

    return 0;
}
