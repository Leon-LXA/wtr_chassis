//
// Created by kevin on 2020/6/23.
//

#ifndef WTR_CAN_MOTOR_VESC_TMOTOR_H
#define WTR_CAN_MOTOR_VESC_TMOTOR_H
#include "wtr_can_motor/common_include.h"
namespace wtr{
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

    class Motor_vesc {
    private:
        int *_DevHandle;
        int _index;            //当前电机在发送报文中德位置
        int CANIndex;
        int _CAN_ID_Send;      // 发送报文的ID
        int _mode; // mode  = 0 速度； mode = 1 角度
        int32_t _target;

        /**
        * @brief 电机基本参数
        * @param None
        * @retval None
        */
        int _motor_id;
        motor_pub_t motorInfo;
        /**
        * @brief 电机反馈解析
        * @param None
        * @retval None
        */
        int16_t buffer_get_int16(uint8_t* buf,int32_t *index){
            int16_t result= ((uint16_t)buf[*index]) <<8 | ((uint16_t)buf[*index+1]);
            (*index)+=2;
            return result;
        }
        uint16_t buffer_get_uint16(uint8_t* buf,int32_t *index){
            uint16_t result= ((uint16_t)buf[*index]) <<8 | ((uint16_t)buf[*index+1]);
            (*index)+=2;
            return result;
        }
        int32_t buffer_get_int32(uint8_t* buf,int32_t *index){
            int32_t result= ((uint32_t)buf[*index]) <<24 |
                            ((uint32_t)buf[*index+1]) <<16 |((uint32_t)buf[*index+2]) <<8  |
                            ((uint32_t)buf[*index+3]);
            (*index)+=4;
            return result;
        }
        float buffer_get_float16(uint8_t* buf,int32_t *index){
            return (float)buffer_get_int16(buf,index);
        }
        float buffer_get_float32(uint8_t* buf,int32_t *index){
            return (float)buffer_get_int32(buf,index);
        }

    public:
        uint8_t CANMsg_send[8];

        Motor_vesc(int mode, uint32_t Motor_number);

        ~Motor_vesc();

        /**
          * @brief 发送电机电流
          * @param
          * @retval None
          */
        bool canTransmit();

        void setDevHandle(int *DevHandle) {
            _DevHandle = DevHandle;
        }

        /**
         * @brief Vesc CAN通信的反馈数据具体解析函数
         * @param 电机数据结构体
         * @retval None
         */
        void canDataReceive(CAN_MSG *CanMsgBuffer);

        motor_pub_t  getMotorInfo(){
//            printf("%lf\n",motorInfo.output_angle);
            return motorInfo;
        };

        void Run(){
            if (_mode == POSITION){
                LOG(ERROR)<<"VESC has not been set for POSITON mode";
            }
            else if( _mode == SPEED){
                canTransmit();
            }
            else{
                for(int i=0;i<8;i++){
                    CANMsg_send[i] = 0;
                }
                canTransmit();
                LOG(FATAL)<<"Motor mode error!!";
            }

        }

        void setTarget(int32_t target){
            _target = target;
        }


    };



}

void wtr::Motor_vesc::canDataReceive(CAN_MSG* CanMsgBuffer) {
    LOG(INFO)<<"receive "<<CanMsgBuffer->ID<<" "<<_CAN_ID_Send;
        if (((uint8_t)CanMsgBuffer->ID) != _CAN_ID_Send){
//            return;
        }

        int cmd =  CanMsgBuffer->ID>>8;
    switch (cmd) {
        case CAN_PACKET_STATUS:{
            // TODO: 设置VESC上位机完成对角度信息的解析。
            motorInfo.output_vol = buffer_get_int32(CanMsgBuffer->Data, &_motor_id);
            motorInfo.current = (float ) (buffer_get_int16(CanMsgBuffer->Data, & _motor_id) / 10.0f);
            LOG(INFO)<<motorInfo.output_vol;
            break;
        }
        default:{
            break;
        }
    }



}


wtr::Motor_vesc::Motor_vesc(int mode, uint32_t Motor_number) {
    _mode = mode;
    _motor_id = Motor_number;
    CANIndex = 0;
    if (_mode == SPEED){
        _CAN_ID_Send = Motor_number | (CAN_PACKET_SET_RPM << 8);
    }
    else{
        LOG(FATAL)<<"FATAL!: The VESC in WTR is now only set for SPEED mode, please check the mode you set.";
    }
}

wtr::Motor_vesc::~Motor_vesc() {
    for(int i=0;i<8;i++){
        CANMsg_send[i] = 0;
    }
    canTransmit();
}


/**
* @brief 发送CAN消息
* @param None
* @retval None
*/
bool wtr::Motor_vesc::canTransmit() {

    // Current to C620 for 4 motors.

    CAN_MSG CanMsg;
    CanMsg.RemoteFlag = 0;
    CanMsg.ExternFlag = 0;
    CanMsg.DataLen = 8;
    CanMsg.ID = _motor_id | (CAN_PACKET_SET_RPM << 8);
    CanMsg.RemoteFlag = 0;
    CanMsg.ExternFlag = 1;
    CanMsg.DataLen = 4;
    CanMsg.Data[0] = _target >> 24;
    CanMsg.Data[1] = _target >> 16;
    CanMsg.Data[2] = _target >> 8;
    CanMsg.Data[3] = _target;


    int SendedNum = CAN_SendMsg(*_DevHandle,CANIndex,&CanMsg,1);
    if(SendedNum >= 0){
//       LOG(INFO)<<"Send to C620 success";
        return true;
    }else{
        LOG(ERROR)<<"Send CAN data failed!\n";
        return false;
    }
}

#endif //WTR_CAN_MOTOR_VESC_TMOTOR_H
