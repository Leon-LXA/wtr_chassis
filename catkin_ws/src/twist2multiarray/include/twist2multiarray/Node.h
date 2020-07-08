//
// Created by ruoyo on 2020/6/27.
//

#ifndef SRC_NODE_H
#define SRC_NODE_H

#define UNDEFINED 0x00
#define SPEED 0x01
#define POSITION 0X02

#define M3508 0x00
#define M2006 0x01
#define M6020 0x02

#define PR 0x01
#define TR 0x02

#include <geometry_msgs/Twist.h>
//#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/UInt8MultiArray.h>
#include <ros/ros.h>
#include <boost/bind.hpp>
#include <iostream>
#include <std_msgs/MultiArrayDimension.h>
// glog
#include <glog/logging.h>
#include <gflags/gflags.h>
struct wheel_t{
    float vel[4];
    float angle[4];
};
const float PI = 3.1415;
const float AFA = 0.141;         //轮子到底盘中心距离(m)

namespace wtr{

    typedef union{
        short data_s;
        uint8_t data_i[2];
    }SHORT_t;

    typedef union{
        float data_s;
        uint8_t data_i[2];
    }FLOAT_t;
    class Node{
    public:
        Node(uint8_t type){
            pub = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/canbus",1,true);
            sub = nh.subscribe<geometry_msgs::Twist>("cmd_vel",10, boost::bind(&Node::CmdCallback, this, _1));
            sub_feedback = nh.subscribe<std_msgs::Float32MultiArray>("angle_feedback",10, &Node::AngFeedback, this);

            uint32_t Size = 8;
            angle.data.resize(Size);
            motorInit(type);
            _type = type;
        }
        //~Node()
        void CmdCallback(const geometry_msgs::Twist::ConstPtr &twist);
        void AngFeedback(const std_msgs::Float32MultiArray::ConstPtr &Ang);
        //extern void adjustSteerAngle(float &targetVel, float &targetAngle_rad, float currentAngle_rad);
    private:
        uint8_t _type;
        std_msgs::Float32MultiArray angle;
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::Subscriber sub;
        ros::Subscriber sub_feedback;

        void motorInit(uint32_t type){
            std_msgs::UInt8MultiArray pub1;
            if(type == TR){
                std_msgs::MultiArrayDimension dims;
                dims.size = 12;
                dims.label = "DJI";
                pub1.layout.dim.push_back(dims);
                //前四位：报头ID
                pub1.data.push_back((uint8_t)(0x300>>24));
                pub1.data.push_back((uint8_t)(0x300>>16));
                pub1.data.push_back((uint8_t)(0x300>>8));
                pub1.data.push_back((uint8_t)(0x300));
                //电机1～4
                pub1.data.push_back(M2006);
                pub1.data.push_back(POSITION);
                pub1.data.push_back(M2006);
                pub1.data.push_back(POSITION);
                pub1.data.push_back(M2006);
                pub1.data.push_back(POSITION);
                pub1.data.push_back(M2006);
                pub1.data.push_back(POSITION);
                pub.publish(pub1);
            }else if (type == PR){
                std_msgs::MultiArrayDimension dims;
                dims.size = 12;
                dims.label = "DJI";
                pub1.layout.dim.push_back(dims);
                //前四位：报头ID
                pub1.data.push_back((uint8_t)(0x300>>24));
                pub1.data.push_back((uint8_t)(0x300>>16));
                pub1.data.push_back((uint8_t)(0x300>>8));
                pub1.data.push_back((uint8_t)(0x300));
                //电机1～4
                pub1.data.push_back(M3508);
                pub1.data.push_back(SPEED);
                pub1.data.push_back(M3508);
                pub1.data.push_back(SPEED);
                pub1.data.push_back(M3508);
                pub1.data.push_back(SPEED);
                pub1.data.push_back(M3508);
                pub1.data.push_back(UNDEFINED);
                pub.publish(pub1);
            }
            else{

                LOG(FATAL)<<"FATAL: Can not define robot besides TR and PR !!";
            }

        }
    };

}


#endif //SRC_NODE_H
