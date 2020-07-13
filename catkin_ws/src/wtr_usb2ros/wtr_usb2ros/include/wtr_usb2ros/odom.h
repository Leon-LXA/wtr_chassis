//
// Created by kevin on 2020/7/12.
//

#ifndef WTR_USB2ROS_ODOM_H
#define WTR_USB2ROS_ODOM_H

#include "wtr_usb2ros/common_include.h"
#include "wtr_usb2ros/can.h"
namespace wtr{

    class Odom{
        long encoder[2];
        long time[2];

    public:
        int32_t can_id[2];
        Odom(){
            can_id[0] = 0x600;
            can_id[1] = 0x601;
        }
        long* getEncoder(){
            return encoder;
        }
        long getTime(){
            return time[0];
        }

        void setEncoderFromCan(CAN_MSG CanMsgBuffer){

            LONG_T time_now;
            LONG_T enc;

            // 左编码器解析
            if(CanMsgBuffer.ID == can_id[LEFT]){
                for(int i = 0 ;i < 4;i ++)
                    time_now.data_i[i] = CanMsgBuffer.Data[i];
                for(int i = 0 ;i < 4;i ++)
                    enc.data_i[i] = CanMsgBuffer.Data[i+4];
                // 时间同步
                if(time_now.data_l - time[RIGHT] < 10){
                    time[LEFT] = time_now.data_l;
                    encoder[LEFT] = enc.data_l;
                } else{
//                    LOG(INFO)<<"Time synchronization error, discard message : "<<time_now.data_l << " " <<enc.data_l;
                    std::cout<<time_now.data_l << " " <<enc.data_l<<std::endl;
                }
            }
            // 右编码器解析
            else if(CanMsgBuffer.ID == can_id[RIGHT]){
                for(int i = 0 ;i < 4;i ++){
                    time_now.data_i[i] = CanMsgBuffer.Data[i];
//                    std::cout<<std::hex()<<time_now.data_i[i];
                }
//                std::cout<<std::endl;
                for(int i = 0 ;i < 4;i ++)
                    enc.data_i[i] = CanMsgBuffer.Data[i+4];
                // 时间同步
                if(time_now.data_l - time[LEFT] < 10){
                    time[RIGHT] = time_now.data_l;
                    encoder[RIGHT] = enc.data_l;
                }else{

                    LOG(INFO)<<"Time synchronization error, discard message : "<<time_now.data_l << " " <<enc.data_l;
//                    std::cout<<time_now.data_l << " " <<enc.data_l<<std::endl;
                }
            }
            else
            {
                LOG(ERROR)<<"The encoder can ID has something wrong!";
            }

        }


    };



}
#endif //WTR_USB2ROS_ODOM_H
