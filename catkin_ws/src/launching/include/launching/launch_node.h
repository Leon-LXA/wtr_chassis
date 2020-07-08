//
// Created by ruoyo on 2020/7/7.
//

#ifndef LAUNCHING_LAUNCH_NODE_H
#define LAUNCHING_LAUNCH_NODE_H

#define UNDEFINED 0x00
#define SPEED 0x01
#define POSITION 0X02

#define M3508 0x00
#define M2006 0x01
#define M6020 0x02

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <ros/ros.h>
#include <iostream>
#include <std_msgs/UInt8MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
// glog
#include <glog/logging.h>
#include <gflags/gflags.h>

namespace wtr {
    class Node {
    public:
        Node() {
            Last = 0;
            pub = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/canbus", 10, true);
            sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &Node::JoyCallback, this);
            array.data.resize(12);
            std_msgs::MultiArrayDimension dims;
            dims.label = "DJI";
            dims.size = 12;
            array.layout.dim.push_back(dims);

            motorInit();
        }

        ~Node() {}

        void pub_id();

    private:
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::Subscriber sub;
        std_msgs::UInt8MultiArray pub1; //注册发送数组
        std_msgs::UInt8MultiArray array;//速度或位置发送数组

        int Last;

        void JoyCallback(const sensor_msgs::Joy::ConstPtr &msg);

        void motorInit() {
            std_msgs::MultiArrayDimension dims;
            dims.label = "DJI";
            dims.size = 12;
            pub1.layout.dim.push_back(dims);
            pub1.data.resize(12);

            pub_id();
        }
    };
}
#endif //LAUNCHING_LAUNCH_NODE_H
