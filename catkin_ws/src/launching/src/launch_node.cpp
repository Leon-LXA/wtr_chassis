//
// Created by ruoyo on 2020/7/7.
//

#include "launching/launch_node.h"


void wtr::Node::JoyCallback(const sensor_msgs::Joy::ConstPtr& msg) {
    int buttons_A = msg->buttons[1];
    int buttons_B = msg->buttons[2];
    float_t speed_change = msg->axes[5];

    int16_t temp;

    if(buttons_A == 0 && buttons_B == 0 && speed_change == 0)
    {
//        LOG(INFO)<<"here";
        Last = 0;
        return;
    }


    array.data[0]=((uint8_t)(0x301>>24));
    array.data[1]=((uint8_t)(0x301>>16));
    array.data[2]=((uint8_t)(0x301>>8));
    array.data[3]=((uint8_t)(0x301));

    if(buttons_A == 0 && buttons_B ==1)
    {
        for (int i = 0; i < 8; ++i)
            array.data[i+4] = 0;
    } else if(buttons_A == 1 && buttons_B == 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            array.data[2*i+4] = (uint8_t)(1000>>8);
            array.data[2*i+5] = (uint8_t)(1000);
        }
    }
    temp = ((array.data[4]<<8)|array.data[5]);
//    LOG(INFO)<<"first" <<temp;
//    LOG(INFO)<<speed_change;
    if(speed_change > 0.8 && Last == 0)
    {
        temp += 200;
        for (int i = 0; i < 4; ++i)
        {
            array.data[2*i+4] = (uint8_t)(temp>>8);
            array.data[2*i+5] = (uint8_t)(temp);
        }
        Last = 1;
    }else if(speed_change < -0.8 && Last == 0)
    {
        temp -=200;
        for (int i = 0; i < 4; ++i)
        {
            array.data[2*i+4] = (uint8_t)(temp>>8);
            array.data[2*i+5] = (uint8_t)(temp);
        }
        Last = 1;
    }


    if (temp<0)  //保证大于等于0,防止反转
    {
        LOG(INFO)<<"小于0";
        for (int i = 0; i < 8; ++i)
            array.data[i+4] = 0;
        temp = 0;
    }
    LOG(INFO)<<"当前转速"<<temp;
//    LOG(INFO)<<"Last是"<<Last;



    pub.publish(array);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "launch_node");
    wtr::Node node;

    ros::spin();
}