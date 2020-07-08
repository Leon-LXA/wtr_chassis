//
// Created by ruoyo on 2020/7/6.
//
#include <std_msgs/Float32.h>
#include <std_msgs/UInt8MultiArray.h>
#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float32.h"
//#include "geometry_msgs/Twist.h"

class Gpio_joy
{
public:
    Gpio_joy();

private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    void JoyCallback(const sensor_msgs::Joy::ConstPtr& msg);
    std_msgs::UInt8MultiArray pub_1,pub_2;
    int32_t gpio_id1 = 0x500;
    int32_t gpio_id2 = 0x501;

};

void Gpio_joy::JoyCallback(const sensor_msgs::Joy::ConstPtr &msg) {

    pub.publish(pub_1);
    if(msg->buttons[7]==1)
    {
        for (int i = 0; i < 8; ++i) {
            pub_2.data[i+4] = 0x01;

        }
        pub.publish(pub_2);
    }
    if(msg->buttons[7]==0)
    {
        for (int i = 0; i < 8; ++i) {
            pub_2.data[i+4] = 0x00;
        }
        pub.publish(pub_2);
    }

}

Gpio_joy::Gpio_joy() {
    pub = nh.advertise<std_msgs::UInt8MultiArray>("/wtr/chassis/gpio",10);
    sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&Gpio_joy::JoyCallback,this);

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
    pub.publish(pub_1);
    std::cout<<"got it!"<<std::endl;
    sleep(1);

    pub_2.data.resize(12);
    pub_2.data[0] = ((uint8_t)(gpio_id2>>24));
    pub_2.data[1] = ((uint8_t)(gpio_id2>>16));
    pub_2.data[2] = ((uint8_t)(gpio_id2>>8));
    pub_2.data[3] = ((uint8_t)(gpio_id2));
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "gpio_ctrl");
    Gpio_joy gpioJoy;

    ros::spin();
}

