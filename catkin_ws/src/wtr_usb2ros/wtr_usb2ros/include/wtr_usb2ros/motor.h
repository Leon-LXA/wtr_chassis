//
// Created by kevin on 2020/7/12.
//

#ifndef WTR_USB2ROS_MOTOR_H
#define WTR_USB2ROS_MOTOR_H

#include "wtr_usb2ros/common_include.h"
namespace wtr{


    class DJI_Motor{
    private:
        void upDateMotorType()
        {
            switch (type) {
                case M3508:
                    reductionRatio = 3591.0f/187.9f;
                    break;
                case M2006:
                    reductionRatio = 36.0f;
                    break;
                case M6020:
                    reductionRatio = 1.0f;
                    break;
                default:{}
            }
        }
    public:
        float _target;
        int32_t msg_cnt;
        float rotor_angle[2], rotor_vol, rotor_pos[2], rotor_round;
        motor_pub_t motorInfo;
        int32_t offsetPos;
        float reductionRatio;
        int mode;
        int type;
        DJI_Motor(){
            mode = UNDEFINED;
            motorInfo.output_angle = 0;
            motorInfo.output_vol = 0;
            motorInfo.current = 0;
            motorInfo.temperature=0;
            offsetPos = 0;
            reductionRatio = 36;

        }
        /**
* @brief 设置电机初始角度
* @param 电机数据结构体
* @retval None
*/
        void getRotorOffset(uint8_t * CanMsgBuffer)
        {
            rotor_pos[NOW] = (uint16_t)(CanMsgBuffer[0]<<8 | CanMsgBuffer[1]);
            offsetPos= rotor_pos[NOW];
        }

/**
* @brief 3508CAN通信的反馈数据具体解析函数
* @param 电机数据结构体
* @retval None
*/
        void canDataDecoder(uint8_t* CanMsgBuffer){
            upDateMotorType();

            // 更新转矩电流
            motorInfo.current = CanMsgBuffer[4]<<8|CanMsgBuffer[5];
            if( motorInfo.current > 32768)
            {
                motorInfo.current-= 65536;
            }

            // 更新电机温度
            motorInfo.temperature = CanMsgBuffer[6];

            //更新位置
            rotor_pos[LAST] = rotor_pos[NOW];
            rotor_angle[LAST] = rotor_angle[NOW];
            rotor_pos[NOW] = CanMsgBuffer[0]<<8|CanMsgBuffer[1];
            //更新速度
            rotor_vol= CanMsgBuffer[2]<<8|CanMsgBuffer[3];
            //更新总转数
            /* 将电机速度反馈值由无符号整型转变为有符号整型 */
            if(rotor_pos[NOW] > 32768)
            {
                rotor_pos[NOW] -= 65536;
            }

            /* 电机圈数更新 */
            if(rotor_pos[NOW] - rotor_pos[LAST] > (ROTER_RANGE / 2))
            {
                rotor_round --;
            }
            else if( rotor_pos[NOW] - rotor_pos[LAST] < -(ROTER_RANGE/2))
            {
                rotor_round ++;
            }
            /* 更新转子当前角度 */
            rotor_angle[NOW] = rotor_pos[NOW] + ROTER_RANGE * rotor_round - offsetPos;
            /* 更新输出轴角度 */
            motorInfo.output_angle = rotor_angle[NOW] *  PI * 2 / reductionRatio  / ROTER_RANGE;
            motorInfo.output_vol = rotor_vol;// / reductionRatio;
            if( motorInfo.output_vol > 32768)
            {
                motorInfo.output_vol-= 65536;
            }
            motorInfo.output_vol /= reductionRatio;
        }
    };


    class VESC_Motor {
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

        VESC_Motor(int mode, uint32_t Motor_number){
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

        ~VESC_Motor() {
            for(int i=0;i<8;i++){
                CANMsg_send[i] = 0;
            }
            canTransmit();
        }

        /**
          * @brief 发送电机电流
          * @param
          * @retval None
          */
        bool canTransmit(){

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


        void setDevHandle(int *DevHandle) {
            _DevHandle = DevHandle;
        }

        /**
         * @brief Vesc CAN通信的反馈数据具体解析函数
         * @param 电机数据结构体
         * @retval None
         */
        void canDataReceive(CAN_MSG *CanMsgBuffer) {
            LOG(INFO) << "receive " << CanMsgBuffer->ID << " " << _CAN_ID_Send;
            if (((uint8_t) CanMsgBuffer->ID) != _CAN_ID_Send) {
//            return;
            }
            int cmd = CanMsgBuffer->ID >> 8;
            switch (cmd) {
                case CAN_PACKET_STATUS: {
                    // TODO: 设置VESC上位机完成对角度信息的解析。
                    motorInfo.output_vol = buffer_get_int32(CanMsgBuffer->Data, &_motor_id);
                    motorInfo.current = (float) (buffer_get_int16(CanMsgBuffer->Data, &_motor_id) / 10.0f);
                    LOG(INFO) << motorInfo.output_vol;
                    break;
                }
                default: {
                    break;
                }
            }
        }

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

#endif //WTR_USB2ROS_MOTOR_H
