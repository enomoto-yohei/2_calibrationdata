// er14000.cpp

#include "ros/ros.h"

#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Float32MultiArray.h>

#include <geometry_msgs/Twist.h>
//#include <ri1/Pose.h>
 
class turtleSim {
public:
    turtleSim();
    ~turtleSim();
//  void poseCallback(const turtlesim::PoseConstPtr& pose);
    void poseCallback(const std_msgs::Float32MultiArray::ConstPtr& array);
    void setMoveVector(float linear_x);
    void setMoveAngular(float angular_z);
    void timerCallback(const ros::TimerEvent&);
 
private:
    ros::Publisher twist_pub;
    ros::Subscriber pose_sub;
    ros::Timer timer;
    ros::NodeHandle nh;
};
 
turtleSim::turtleSim()
{
    twist_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    pose_sub = nh.subscribe<std_msgs::Float32MultiArray>("turtle1/pose", 1, 
					     &turtleSim::poseCallback, this);
    timer = nh.createTimer(ros::Duration(0.1), &turtleSim::timerCallback, this);
 
    geometry_msgs::Twist twist;

    twist.linear.x = 0.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.0;
    twist_pub.publish(twist);
}
 
turtleSim::~turtleSim()
{
// nothing here now. 
}
 
void turtleSim::poseCallback(const std_msgs::Float32MultiArray::ConstPtr& array)
{
    float fx[128]; // x coordinate of objects found
    float fy[128]; // y coordinate of objects found
    int	  fkind[128]; // kind of objects found

    float x = array -> data[0]; // x coordinate of zorimushi
    float y = array -> data[1]; // y coordinate of zorimushi
    float orient = array -> data[2]; // orientation of zorimushi
    float v = array -> data[3]; // linear velocity of zorimushi
    float a = array -> data[4]; // angular velocity of zorimushi
    float life = array -> data[5]; // angular velocity of zorimushi
    int	numfinds = (int)(array -> data[6]); // number of objects found

    for (int i = 7, j = 0; i < 7 + numfinds*3; i += 3, j++) {
        fx[j] = array -> data[i];
	fy[j] = array -> data[i+1];
	fkind[j] = (int)(array -> data[i+2]);
    }

    geometry_msgs::Twist twist;
 
////////////////////////////////////////////////////////////////

    ROS_INFO("x:%.1f y:%.1f o:%.1f v:%.1f a:%.1f life:%.1f num:%d", 
	     x, y, orient, v, a, life, numfinds);
    for (int i = 0; i < numfinds; i++) {
        ROS_INFO("fx[%d]%.1f fy[%d]%.1f fkind[%d]%d ", 
		 i, fx[i], i, fy[i], i, fkind[i]);
    }

// Write your intelligence here.

    static int timing = 0;   // timing control
    static float apub = 8.0; // angular velocity for publish
    static float vpub = 3.0; // linear velocity for publish

    if (0 == (timing++ % 10)) {
        twist.angular.z = apub;
	apub -= 0.1;
    }
    else {
        twist.linear.x = vpub;
    }

////////////////////////////////////////////////////////////////

    twist_pub.publish(twist);
}

void turtleSim::timerCallback(const ros::TimerEvent&)
{
//  Now we do not use this programs' ROS timer
}
 
void turtleSim::setMoveVector(float linear_x)
{
//  geometry_msgs::Twist twist;
 
//  twist.linear.x = linear_x;
//  twist_pub.publish(twist);
}

void turtleSim::setMoveAngular(float angular_z)
{
//  geometry_msgs::Twist twist;

//  twist.angular.z = angular_z;
//  twist_pub.publish(twist);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_turtlesim");
 
    turtleSim turtlesim;

    ros::spin();
    return 0;
}

