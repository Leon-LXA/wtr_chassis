//
// Created by ruoyo on 2020/7/7.
//

#include "launching/launch_node.h"


void wtr::Node::JoyCallback(const sensor_msgs::Joy::ConstPtr& msg) {
    int buttons_A = msg->buttons[1]; //默认开启开关
    int buttons_B = msg->buttons[2]; //急停开关
    float_t speed_change = msg->axes[5]; //上下按钮控制速度改变

    int16_t temp; //寄存当前电机速度绝对值

    if(buttons_A == 0 && buttons_B == 0 && speed_change == 0) //若对遥控器没有指令，则直接return退出回调
    {
//        LOG(INFO)<<"here";
        Last = 0;
        return;
    }

    //报头0x301,控制1到4号电机
    array.data[0]=((uint8_t)(0x301>>24));
    array.data[1]=((uint8_t)(0x301>>16));
    array.data[2]=((uint8_t)(0x301>>8));
    array.data[3]=((uint8_t)(0x301));

    if(buttons_A == 0 && buttons_B ==1) //急停开关B
    {
        for (int i = 0; i < 8; ++i)
            array.data[i+4] = 0;
    } else if(buttons_A == 1 && buttons_B == 0) //默认速度开启开关A
    {
        for (int i = 0; i < 2; ++i)
        {
            //1号3号电机正转
            array.data[4*i+4] = (uint8_t)(3000>>8);
            array.data[4*i+5] = (uint8_t)(3000);
            //2号4号电机反转
            array.data[4*i+6] = (uint8_t)((-3000)>>8);
            array.data[4*i+7] = (uint8_t)(-3000);
        }
    }
    temp = ((array.data[4]<<8)|array.data[5]);
//    LOG(INFO)<<"first" <<temp;
//    LOG(INFO)<<speed_change;
    if(speed_change > 0.8 && Last == 0) //上下按钮可以增减速度
    {
        temp += 500;
        for (int i = 0; i < 2; ++i)
        {
            //1号3号电机正转
            array.data[4*i+4] = (uint8_t)(temp>>8);
            array.data[4*i+5] = (uint8_t)(temp);
            //2号4号电机反转
            array.data[4*i+6] = (uint8_t)((-temp)>>8);
            array.data[4*i+7] = (uint8_t)(-temp);
        }
        Last = 1;
    }else if(speed_change < -0.8 && Last == 0)
    {
        temp -=500;
        for (int i = 0; i < 2; ++i)
        {
            //1号3号电机正转
            array.data[4*i+4] = (uint8_t)(temp>>8);
            array.data[4*i+5] = (uint8_t)(temp);
            //2号4号电机反转
            array.data[4*i+6] = (uint8_t)((-temp)>>8);
            array.data[4*i+7] = (uint8_t)(-temp);
        }
        Last = 1;
    }


    if (temp<0)  //保证大于等于0,防止1号3号反转、2号4号正转
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

void wtr::Node::pub_id() {
    //前四位：报头ID
    pub1.data[0]=((uint8_t) (0x300 >> 24));
    pub1.data[1]=((uint8_t) (0x300 >> 16));
    pub1.data[2]=((uint8_t) (0x300 >> 8));
    pub1.data[3]=((uint8_t) (0x300));
    //电机1～4
    pub1.data[4]=(M3508);
    pub1.data[5]=(SPEED);
    pub1.data[6]=(M3508);
    pub1.data[7]=(SPEED);
    pub1.data[8]=(M3508);
    pub1.data[9]=(SPEED);
    pub1.data[10]=(M3508);
    pub1.data[11]=(SPEED);

    pub.publish(pub1);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "launch_node");
//    LOG(INFO)<<"Here";
    wtr::Node node;


    ros::Time begin_time = ros::Time::now();
    ros::Duration wait_while(3,0);
    ros::Time last_time = begin_time;

    while(!ros::isShuttingDown())
    {
        ros::Time now_time = ros::Time::now();
        if( (now_time-last_time) > wait_while)
        {
            last_time = now_time;
            node.pub_id();//每3秒重新注册一次电机信息
        }
        ros::spinOnce();
    }
    LOG(INFO)<<"Shutdown";
    google::ShutdownGoogleLogging();

    return 0;
}
