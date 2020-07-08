//
// Created by kevin on 2020/5/31.
//

#include "wtr_can_motor/common_include.h"

using namespace std;

typedef union{
    short data_s;
    uint8_t data_i[2];
}SHORT_T;

void motor_example()
{
    ros::NodeHandle nh;
    ros::Publisher pub_ctrl;
    pub_ctrl = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/canbus",1,true);
    int8_t speed = -1;

    std_msgs::UInt8MultiArray pub;
    uint32_t dataSize = 12 ;

    pub.layout.dim.push_back(std_msgs::MultiArrayDimension());
    pub.layout.dim[0].size = dataSize;
    pub.layout.dim[0].label = "DJI";
    pub.data.resize(dataSize);


    int32_t can_id = 0x0300;
    pub.data[0]=((uint8_t)(can_id>>24));
    pub.data[1]=((uint8_t)(can_id>>16));
    pub.data[2]=((uint8_t)(can_id>>8));
    pub.data[3]=((uint8_t)(can_id));

    pub.data[4]=(M2006);
    pub.data[5]=(SPEED);
    pub.data[6]=(M3508);
    pub.data[7]=(UNDEFINED);
    pub.data[8]=(M2006);
    pub.data[9]=(UNDEFINED);
    pub.data[10]=(M6020);
    pub.data[11]=(UNDEFINED);
    pub_ctrl.publish(pub);
}
void gpio_example()
{
    ros::NodeHandle nh;
    ros::Publisher pub_gpio;

    pub_gpio = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/chassis/gpio",1,true);
    std_msgs::UInt8MultiArray pub_1,pub_2;

    int32_t gpio_id1 = 0x500;
    int32_t gpio_id2 = 0x501;
    pub_1.data.push_back((uint8_t)(gpio_id1>>24));
    pub_1.data.push_back((uint8_t)(gpio_id1>>16));
    pub_1.data.push_back((uint8_t)(gpio_id1>>8));
    pub_1.data.push_back((uint8_t)(gpio_id1));

    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_1.data.push_back(0x1);
    pub_gpio.publish(pub_1);

    pub_2.data.push_back((uint8_t)(gpio_id2>>24));
    pub_2.data.push_back((uint8_t)(gpio_id2>>16));
    pub_2.data.push_back((uint8_t)(gpio_id2>>8));
    pub_2.data.push_back((uint8_t)(gpio_id2));

    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_2.data.push_back(0x1);
    pub_gpio.publish(pub_2);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "controller");



    ros::NodeHandle nh;
    ros::Publisher pub_ctrl,pub_gpio;

    pub_gpio = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/chassis/gpio",10,true);//注意消息池大小！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

    while(!ros::isShuttingDown()) {

        std_msgs::UInt8MultiArray pub_1,pub_2;

        int32_t gpio_id1 = 0x500;
        int32_t gpio_id2 = 0x501;
        pub_1.data.push_back((uint8_t)(gpio_id1>>24));
        pub_1.data.push_back((uint8_t)(gpio_id1>>16));
        pub_1.data.push_back((uint8_t)(gpio_id1>>8));
        pub_1.data.push_back((uint8_t)(gpio_id1));

        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_1.data.push_back(0x1);
        pub_gpio.publish(pub_1);

        pub_2.data.push_back((uint8_t)(gpio_id2>>24));
        pub_2.data.push_back((uint8_t)(gpio_id2>>16));
        pub_2.data.push_back((uint8_t)(gpio_id2>>8));
        pub_2.data.push_back((uint8_t)(gpio_id2));

        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_2.data.push_back(0x1);
        pub_gpio.publish(pub_2);

        sleep(1);
        for (int i = 0; i < 8; ++i) {
            pub_2.data[(i+4)] = 0x00;
        }
        pub_gpio.publish(pub_2);
        sleep(1);
    }
    return 0;
}

