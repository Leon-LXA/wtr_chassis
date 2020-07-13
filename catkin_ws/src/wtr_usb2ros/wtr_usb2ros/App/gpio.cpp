//
// Created by ruoyo on 2020/7/4.
//
#include "wtr_usb2ros/can.h"
#include "wtr_usb2ros/gpio.h"

wtr::gpio::gpio() {
    int ret = USB_ScanDevice(DeviceHandle);
    if(ret <= 0){
        LOG(INFO)<<"No device connected!";

    }else{
        LOG(INFO)<<"Found Devices:";
        for(int i=0;i<ret;i++){
            LOG(INFO)<<DeviceHandle[i];
        }
    }
    bool state;

    state = USB_OpenDevice(DeviceHandle[0]);
    if(!state){
        LOG(INFO)<<"Open device error!";
    }

//    DEVICE_INFO DevInfo;
//    char FuncStr[256]={0};
//    state = DEV_GetDeviceInfo(DeviceHandle[0],&DevInfo,FuncStr);

    DEV_SetPowerLevel(DeviceHandle[0],POWER_LEVEL_3V3);
    LOG(INFO)<<"created";

    sub_gpio = nh_gpio.subscribe<std_msgs::UInt8MultiArray>("/wtr/chassis/gpio",10,
            boost::bind(&wtr::gpio::gpioCallback, this, _1));//注意消息池的大小！！！！

//    run();
//    GPIO_SetOutput(DeviceHandle[0],0xFF00,GPIO_PUPD_UP);
//    GPIO_Write(DeviceHandle[0],0xFF00,0x0000);
}

void wtr::gpio::gpioCallback(const std_msgs::UInt8MultiArray::ConstPtr &msg) {

    std_msgs::UInt8MultiArray array;
    int up = 0;
    int down = 0;
    int none = 0;
    int set = 0;
    int reset = 0;
    int ret;

    array.data = msg->data;
    ID_gpio = array.data[0] << 24 | array.data[1] << 16 |
           array.data[2] << 8 | array.data[3];

//    GPIO_SetOutput(DeviceHandle[0],0xFF00,GPIO_PUPD_UP);
//    GPIO_Write(DeviceHandle[0],0xFF00,0xFF00);
//    LOG(INFO)<<msg->data[0];
//    LOG(INFO)<<ID_gpio;
    switch (ID_gpio){
        case 0x500:
        {
            for (int i = 4; i < 12; ++i) {
                if(array.data[i] == PULLUP)
                    up |= ( 1 << (i+8-4) ); //其中+8指的是因为要控制P8到P15，即0x0100到0x8000，低2位不使用，因此需要左移8位，而由于报头的存在，因此array里面的信息值是从4开始的，需要-4
                if(array.data[i] == PULLDOWN)
                    down |= ( 1 << (i+8-4) );
                if(array.data[i] == PULLNONE)
                    none |= ( 1 << (i+8-4) );
            }
//            LOG(INFO)<<"SetOutput";
//            std::cout<<std::hex<<up<<std::endl;
//            std::cout<<std::hex<<down<<std::endl;
//            std::cout<<std::hex<<none<<std::endl;
            GPIO_SetOutput(DeviceHandle[0],up,GPIO_PUPD_UP);
            GPIO_SetOutput(DeviceHandle[0],down,GPIO_PUPD_DOWN);
            GPIO_SetOutput(DeviceHandle[0],none,GPIO_PUPD_NOPULL);

            break;
        }
        case 0x501:
        {
            for (int i = 4; i < 12; ++i) {
                if(array.data[i] == SET)
                    set = set | ( 1 << (i+8-4) );
                if(array.data[i] == RESET)
                    reset = reset | ( 1 << (i+8-4) );
            }

            ret = GPIO_Write(DeviceHandle[0],0xFF00,set);
            if(ret == 0)
                LOG(INFO)<<"sent";
            break;
        }
        default:{}
    }

}

int main(int argc, char** argv)
{
    ros::init(argc, argv,"gpio111");
    wtr::gpio gpio1;

    ros::spin();
}
