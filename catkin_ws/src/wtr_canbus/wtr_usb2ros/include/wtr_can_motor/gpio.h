//
// Created by ruoyo on 2020/7/3.
//

#ifndef SRC_GPIO_H
#define SRC_GPIO_H

#include "common_include.h"

#define PULLNONE 0
#define PULLUP   1
#define PULLDOWN 2
#define SET      1
#define RESET    0

namespace wtr{
    class gpio{
    private:
        int DeviceHandle[10];
        int ID_gpio;// 0x500 配置P8～P15引脚上下拉 0x501 配置是否开启
        ros::NodeHandle nh_gpio;
        ros::Subscriber sub_gpio;
        void gpioCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg);
    public:
        gpio();
        ~gpio(){};
    };


}

//void run(){
//    int DeviceHandle[10];
//    int ret = USB_ScanDevice(DeviceHandle);
//    bool state;
//
//    LOG(INFO)<<DeviceHandle[0];
//    state = USB_OpenDevice(DeviceHandle[0]);
//    if(!state){
//        printf("Open device error!\n");
//        return;
//    }
//    DEV_SetPowerLevel(DeviceHandle[0],POWER_LEVEL_3V3);
//
////将P0到P7配置为上拉输出模式
////    GPIO_SetOutput(DeviceHandle[0],0x00FF,GPIO_PUPD_UP);
//
////将P8到P15配置为下拉输出模式
//    GPIO_SetOutput(DeviceHandle[0],0xFFFF,0);
//    while(1)
//    {
//        ret = GPIO_Write(DeviceHandle[0],0xFFFF,0x5555);
//        sleep(1);
//        printf("sent111\n");
//        LOG(INFO)<<"111";
//        ret = GPIO_Write(DeviceHandle[0],0xFFFF,0xAAAA);
//        sleep(1);
//    }
//
//    if(ret == GPIO_SUCCESS) {
//        printf("控制引脚成功\n");
//        return;
//    }
//    if(ret != GPIO_SUCCESS){
//        printf("控制引脚失败\n");
//        return;
//    }
//
//}



#endif //SRC_GPIO_H
