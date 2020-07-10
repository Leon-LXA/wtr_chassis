//
// Created by ruoyo on 2020/7/10.
//

#ifndef CATKIN_WS_NODE_H
#define CATKIN_WS_NODE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
// glog
#include <glog/logging.h>
#include <gflags/gflags.h>

namespace wtr{
    class odom{
    public:
        odom();
        void calculate_pos();
    private:
        void cmdCallback(const geometry_msgs::Twist::ConstPtr& msg);

        ros::NodeHandle nh;
        ros::Subscriber sub;

        ros::Time last;
        ros::Time now;
        ros::Duration duration;

        geometry_msgs::Pose2D pose;

        geometry_msgs::Twist twist;
        int count;
        double dura;
    };
}
#endif //CATKIN_WS_NODE_H
