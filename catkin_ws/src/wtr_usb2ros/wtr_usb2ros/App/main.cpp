//
// Created by kevin on 2020/6/22.
//
#include "wtr_usb2ros/gpio.h"
#include "wtr_usb2ros/can.h"
#include "wtr_usb2ros/common_include.h"
#include "wtr_usb2ros/node.h"


// 创建互斥锁
pthread_mutex_t mutexs;

using namespace std;
void *thread(void *ptr) {
    struct timespec tn_b,tn_e;
    clock_t startTime,endTime;
    while (!ros::isShuttingDown()) {
        clock_gettime(CLOCK_REALTIME, &tn_b);
        pthread_mutex_lock(&mutexs);// 互斥锁
        pthread_mutex_unlock(&mutexs);
        clock_gettime(CLOCK_REALTIME, &tn_e);
//        cout << "The run time is: " <<(double)(tn_e.tv_nsec - tn_b.tv_nsec) / 1000 << "us" << endl;
    }

    return 0;
}


int main(int argc, char **argv){
    ros::init(argc, argv, "can_motor");
    // 开启谷歌调试
    google::InitGoogleLogging(argv[0]);
    FLAGS_stderrthreshold=google::INFO;
    FLAGS_colorlogtostderr=true;
    //
    wtr::CAN canHandle;
    int* DevHandle = canHandle.findDevice();
    canHandle.canInit();
    wtr::Node nh;

    // 初始化多线程
//    pthread_t id;
//    pthread_mutex_init(&mutexs, NULL);
//    int ret = pthread_create(&id, NULL, thread, NULL);
//    if(ret) {
//        LOG(FATAL)<< "Create pthread error!" ;
//    }

    CAN_MSG CanMsgBuffer[100];
    int cntt = 0;
    LOG(INFO)<<"Find device.";
    while(!ros::isShuttingDown())
    {
        canHandle.canReadMsg();
        canHandle.canTransmit(nh.ID_x,nh.Data,nh.type);
        if(cntt++>100){
//            nh.pubAngles(canHandle.getMotorAngles());
            nh.DJIPub(canHandle.getMotorsHandle());
            nh.odomPub(canHandle.odom.getTime(),canHandle.odom.getEncoder());
            nh.vescPub(canHandle.vesc_can_id, canHandle.vesc_can_msg);
            cntt = 0;
        }

        ros::spinOnce();
    }
    LOG(INFO)<<"Closing";
    google::ShutdownGoogleLogging();
    return 0;

}

