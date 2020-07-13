//
// Created by ruoyo on 2020/6/27.
//

#include "twist2multiarray/Node.h"
#include "twist2multiarray/ThreeWheelControl.h"
#include "twist2multiarray/FourWheelControl.h"
//wtr::Node() {
//    pub = nh.advertise<std_msgs::UInt8MultiArray>("cmd_array",1,true);
//    sub = nh.subscribe<geometry_msgs::Twist>("cmd_vel",10,&wtr::Node::CmdCallback,this);
//}



void wtr::Node::CmdCallback(const geometry_msgs::Twist::ConstPtr &twist) {
//    std_msgs::UInt8MultiArray pub1,pub2;
//    motorInit(_type);
    float vx = twist->linear.x;
    float vy = twist->linear.y;
    float w  = twist->angular.z;

    if(vx >  5)     vx = 5;
    if(vx < -5)     vx = -5;
    if(vy >  5)     vy = 5;
    if(vy < -5)     vy = -5;
    if(w > 2*PI)    w = 2*PI;
    if(w < -2*PI)   w = -2*PI;

    if(_type == PR){
        twc(vx, vy, w);
        SHORT_t speed_short[3];
        for (int i = 0; i < 3; ++i) {
            speed_short[i].data_s=(short)(wheel_3.vel[i]* 60*3591.0f/187.0f/0.15/PI) ;
        }
        std_msgs::UInt8MultiArray pub2;
        std_msgs::MultiArrayDimension dims;
        dims.size = 12;
        dims.label = "DJI";
        pub2.layout.dim.push_back(dims);
        //前四位：报头ID
        pub2.data.push_back((uint8_t)(0x301>>24));
        pub2.data.push_back((uint8_t)(0x301>>16));
        pub2.data.push_back((uint8_t)(0x301>>8));
        pub2.data.push_back((uint8_t)(0x301));
        for(int i=0;i<3;i++){
            pub2.data.push_back(speed_short[i].data_i[0]);
            pub2.data.push_back(speed_short[i].data_i[1]);
        }
        pub2.data.push_back(((uint8_t)0x0000>>8));
        pub2.data.push_back((uint8_t)0x0000);
        pub.publish(pub2);

    }else if (_type == TR){
        float vel = sqrt(pow(twist->linear.y, 2) + pow(twist->linear.x, 2));
        float ang = atan2(twist->linear.x, twist->linear.y) + PI / 2;
//           std::cout << angle * 180 / PI << std::endl;
        SHORT_t steer[4];
        FLOAT_t speed[4];
            fwc(vel, ang, twist->angular.z);
            for (int i = 0; i < 4; i++) {
                adjustSteerAngle(wheel.vel[i], wheel.angle[i], angle.data[i]);
                speed[i].data_s =(float)  wheel.vel[i];
                steer[i].data_s =(short) wheel.angle[i];
            }

        std_msgs::UInt8MultiArray pub_dji;
        std_msgs::MultiArrayDimension dims;
        dims.size = 12;
        dims.label = "DJI";
        pub_dji.layout.dim.push_back(dims);
        //前四位：报头ID
        pub_dji.data.push_back((uint8_t)(0x301>>24));
        pub_dji.data.push_back((uint8_t)(0x301>>16));
        pub_dji.data.push_back((uint8_t)(0x301>>8));
        pub_dji.data.push_back((uint8_t)(0x301));

        for(int i=0;i<4;i++){
            pub_dji.data.push_back(steer[i].data_i[1]);
            pub_dji.data.push_back(steer[i].data_i[0]);
        }
        pub.publish(pub_dji);

        std_msgs::UInt8MultiArray pub_vesc[4];
        dims.size = 12;
        dims.label = "VESC";
        for(uint32_t i = 0;i<4;i++){
            pub_vesc[i].layout.dim.push_back(dims);
            //前四位：报头ID
            pub_vesc[i].data.push_back((uint8_t)(i>>24));
            pub_vesc[i].data.push_back((uint8_t)(i>>16));
            pub_vesc[i].data.push_back((uint8_t)(i>>8));
            pub_vesc[i].data.push_back((uint8_t)(i));
            for(int j=0;j<4;j++){
                for(int k = 0; k< 4;k++){
                    pub_vesc[i].data.push_back(steer[j].data_i[k]);
                }
            }

            pub.publish(pub_vesc[i]);
        }

    } else{
        LOG(ERROR)<<"ERROR:You should choose TR or PR as the robot type!";
    }

}

void wtr::Node::AngFeedback(const std_msgs::Float32MultiArray::ConstPtr &Ang) {
    for (int i = 0; i < 8; ++i) {
        angle.data[i] = Ang->data[i];
    }
}