//
// Created by root on 2020/5/29.
//

#ifndef USB2XXX_COMMON_INCLUDE_H
#define USB2XXX_COMMON_INCLUDE_H
#define OS_UNIX
// System
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <ctime>

// USB2XXX
#include "USB2XXX/usb2can.h"
#include "USB2XXX/usb_device.h"
#include "USB2XXX/usb2gpio.h"


// ROS
#include <ros/ros.h>
#include <ros/console.h>
#include <wtr_usb2ros/motor_msgs.h>
#include <wtr_usb2ros/Test.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/UInt8MultiArray.h>
// glog
#include <glog/logging.h>
#include <gflags/gflags.h>

// boost
#include <boost/bind.hpp>
////#include <boost/thread.hpp>
//#include <boost/thread/thread.hpp>
//#include <boost/asio.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
// thread
#include <unistd.h>
#include <pthread.h>

// const variable
const float PI = 3.141592f;
const int LAST = 1;
const int NOW = 0;
const int ROTER_RANGE = 8192;

typedef struct {
    float output_angle, output_vol;
    float temperature, current;
}motor_pub_t;


typedef union{
    short data_s;
    uint8_t data_i[2];
}SHORT_t;
typedef union{
    int32_t data_i;
    uint8_t data_ui[4];
}INT_T;


typedef union{
    float data_f;
    uint8_t data_i[4];
}FLOAT_T;

typedef union{
    int32_t data_l;
    uint8_t data_i[4];
}LONG_T;

typedef enum {
    CAN_PACKET_SET_DUTY = 0,
    CAN_PACKET_SET_CURRENT,
    CAN_PACKET_SET_CURRENT_BRAKE,
    CAN_PACKET_SET_RPM,
    CAN_PACKET_SET_POS,
    CAN_PACKET_FILL_RX_BUFFER,
    CAN_PACKET_FILL_RX_BUFFER_LONG,
    CAN_PACKET_PROCESS_RX_BUFFER,
    CAN_PACKET_PROCESS_SHORT_BUFFER,
    CAN_PACKET_STATUS,
    CAN_PACKET_SET_CURRENT_REL,
    CAN_PACKET_SET_CURRENT_BRAKE_REL,
    CAN_PACKET_SET_CURRENT_HANDBRAKE,
    CAN_PACKET_SET_CURRENT_HANDBRAKE_REL
}CAN_PACKET_ID;

#define M3508 0x00
#define M2006 0x01
#define M6020 0x02

#define UNDEFINED 0x00
#define SPEED 0x01
#define POSITION 0x02

#define VESC 0x01
#define DJI 0x00

#define LEFT 0
#define RIGHT 1

#endif //USB2XXX_COMMON_INCLUDE_H
