#include <geometry_msgs/PointStamped.h>
#include "ros/ros.h"

void GetRPY(const geometry_msgs::Quaternion &q,double &roll,double &pitch,double &yaw);



int main(int argc, char **argv){
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh;
void GetRPY(const geometry_msgs::Quaternion &q,
    double &roll,double &pitch,double &yaw){
  tf::Quaternion quat(q.x,q.y,q.z,q.w);
  tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);
}
    ROS_INFO("hello",GetRPY);

    return 0;
}
