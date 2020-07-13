//
// Created by kevin on 2020/7/12.
//

#ifndef WTR_USB2ROS_NODE_H
#define WTR_USB2ROS_NODE_H
#include "wtr_usb2ros/common_include.h"
namespace wtr{
    class Node{
        ros::NodeHandle nh_;
        ros::Publisher motor_pub[8];
        ros::Publisher vesc_raw_pub;
        ros::Subscriber motor_sub;
        ros::Publisher angle_pub;
        ros::Publisher odom_node;
        std_msgs::UInt8MultiArray msgs;

        void motorCb(const std_msgs::UInt8MultiArray::ConstPtr &msg) {
            msgs = *msg;
            ID_x = msg->data[0] << 24 | msg->data[1] << 16 |
                   msg->data[2] << 8 | msg->data[3];

            for( int i = 0;i<8;i++){
                Data[i] = msg->data[i+4];
            }
            if(msg->layout.dim[0].label == "DJI"){
                type = DJI;
            }
            else if (msg -> layout.dim[0].label == "VESC")
            {
                type = VESC;
            }
            else{
                LOG(ERROR)<<"The can message type is not defined. Is it a VESC or DJI?";
            }
//            LOG(INFO)<<Data[1];
        }
    public:
        uint32_t ID_x;
        uint8_t Data[8];
        int type;
        int types[8];
        int modes[8];
        Node()
        {

            motor_sub = nh_.subscribe<std_msgs::UInt8MultiArray>("/wtr/canbus", 1, boost::bind(&Node::motorCb, this, _1));
            vesc_raw_pub = nh_.advertise<std_msgs::UInt8MultiArray>("/wtr/canbus/vesc/feedback",1);
            angle_pub = nh_.advertise   <std_msgs::Float32MultiArray> ( "/wtr/canbus/DJI/angles", 1);
            motor_pub[0] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/0", 1);
            motor_pub[1] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/1", 1);
            motor_pub[2] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/2", 1);
            motor_pub[3] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/3", 1);
            motor_pub[4] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/4", 1);
            motor_pub[5] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/5", 1);
            motor_pub[6] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/6", 1);
            motor_pub[7] = nh_.advertise<wtr_usb2ros::motor_msgs>("/wtr/canbus/DJI/7", 1);
            odom_node = nh_.advertise<std_msgs::UInt8MultiArray>("/wtr/odom/raw",1);

        }
        /**
        * @brief  电机状态发布函数
        * @param
        * @retval
        */
        void DJIPub(DJI_Motor* motor)
        {
            ros::Time time_now = ros::Time::now();
            wtr_usb2ros::motor_msgs pub;
            pub.header.stamp = time_now;
            for(int i = 0; i < 8 ; i++ ){
                if(motor[i].mode != UNDEFINED){
                    if(motor[i].type != M2006)
                        pub.temperature = motor[i].motorInfo.temperature;

                    pub.angle =motor[i].motorInfo.output_angle;
                    pub.speed = motor[i].motorInfo.output_vol;
                    pub.current = motor[i].motorInfo.current;
                    motor_pub[i].publish(pub);

                }
            }
        }

        /**
        * @brief  vesc can 接受发布函数
        * @param
        * @retval
        */
        void vescPub(uint32_t can_id, uint8_t* msg)
        {
            std_msgs::UInt8MultiArray pub;
            const uint32_t dataSize = 12 ;
            pub.layout.dim.push_back(std_msgs::MultiArrayDimension());
            pub.layout.dim[0].size = dataSize;
            pub.layout.dim[0].label = "VESC_BACK";
            pub.data.resize(dataSize);

            pub.data[0]=((uint8_t)(can_id>>24));
            pub.data[1]=((uint8_t)(can_id>>16));
            pub.data[2]=((uint8_t)(can_id>>8));
            pub.data[3]=((uint8_t)(can_id));
            for(int i = 0 ; i < 8 ; i ++){
                pub.data[i+4]=msg[i];

            }
            vesc_raw_pub.publish(pub);
        }
        /**
        * @brief  电机状态发布函数
        * @param
        * @retval
        */

        void pubAngles(float *msg){
            std_msgs::Float32MultiArray MSG;
            if(msg!=NULL){
                for(int i=0;i<8;i++)
                {

                    MSG.data.push_back(msg[i]);
                }
                angle_pub.publish(MSG);}

        }

        /**
      * @brief odom状态发布函数
      * @param
      * @retval
      */

        void odomPub(long time, long* encoder){
            std_msgs::UInt8MultiArray MSG;
            std_msgs::MultiArrayDimension dims;
            dims.size = 12;
            dims.label = "Odom";
            MSG.layout.dim.push_back(dims);
            MSG.data.resize(dims.size);
            LONG_T time_pub,encoder_pub[2];
            time_pub.data_l = time;
            encoder_pub[0].data_l = encoder[0];
            encoder_pub[1].data_l = encoder[1];
            for(int i=0;i<4;i++){
                MSG.data[i] = time_pub.data_i[i];
                MSG.data[i+4] = encoder_pub[LEFT].data_i[i];
                MSG.data[i+8] = encoder_pub[RIGHT].data_i[i];
            }
            odom_node.publish(MSG);
        }

    };
}
#endif //WTR_USB2ROS_NODE_H
