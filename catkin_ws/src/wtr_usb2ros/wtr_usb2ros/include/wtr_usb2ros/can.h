//
// Created by kevin on 2020/6/22.
//

#ifndef WTR_CAN_MOTOR_CAN_COMMUTE_H
#define WTR_CAN_MOTOR_CAN_COMMUTE_H
#include "wtr_usb2ros/common_include.h"
#include "wtr_usb2ros/motor.h"
#include "wtr_usb2ros/odom.h"
namespace wtr{


    class CAN{
    private:
        void deInit(){
            uint32_t can_id = 0x300;
            uint8_t stop[8] = {0,0,0,0,0,0,0,0};
            canTransmit(can_id, stop, DJI);
            can_id = 0x302;
            canTransmit(can_id, stop, DJI);
//            for (int i=0;i<4;i++){
//                can_id = i;
//                canTransmit(can_id, stop, VESC);
//            }
        }

        /**
       * @brief CAN 通信基本参数
       * @param None
       * @retval None
       */
        int DevHandle[10];
        int CANIndex;
        int type;
        bool isDJIFdb;

        DEVICE_INFO DevInfo;
        CAN_INIT_CONFIG CANConfig;
        CAN_FILTER_CONFIG CANFilter;
        CAN_MSG CanMsgBuffer[100];            //can接收消息池大小
        DJI_Motor Motors[8];

        void canDataDecoder(uint8_t* CanMsgBuffer);
        float fdb[8]={0};
        /**
        * @brief VESC电机反馈解析
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
        wtr::Odom odom;
        uint32_t vesc_can_id;
        uint8_t  vesc_can_msg[8];
        CAN(){
            for(int i = 0;i<8;i++){
                Motors[i].rotor_angle[0] = 0;
            }
            CANIndex = 0;
        };
        ~CAN() {
            deInit();
            usleep(500 * 1000);
            USB_CloseDevice(DevHandle[0]);
            LOG(INFO)<<"Closing USB";
        }

        DJI_Motor* getMotorsHandle(){
            return Motors;
        }

        float* getMotorAngles(){
            for(int i = 0;i<8;i++){
                fdb[i] = Motors[i].motorInfo.output_angle;
            }
            return fdb;
        }


        /**
       * @brief  初始化USB设备，并扫描设备连接数，必须调用
       * @param
       * @retval
       */
        int* findDevice() {
            bool state;
            int ret;
            //扫描查找设备
            ret = USB_ScanDevice(DevHandle);
            if(ret <= 0){
                LOG(FATAL)<<"No device connected!\n";
            }
            else{
//        LOG(INFO)<<"Find "<<ret<<" device.";
                printf("Find %d device.\n",ret);
            }
            //打开设备
            state = USB_OpenDevice(DevHandle[0]);
            if(!state){
                LOG(FATAL)<<"Open device error!\n";
            }
            char FunctionStr[256]={0};
            //获取固件信息
            state = DEV_GetDeviceInfo(DevHandle[0],&DevInfo,FunctionStr);
            if(!state){
                LOG(FATAL)<<"Get device infomation error!\n";
            }else {

                printf("Firmware Info:\n");
                printf("\tFirmware Name:%s\n", DevInfo.FirmwareName);
                printf("\tFirmware Build Date:%s\n", DevInfo.BuildDate);
                printf("\tFirmware Version:v%d.%d.%d\n", (DevInfo.FirmwareVersion >> 24) & 0xFF,
                       (DevInfo.FirmwareVersion >> 16) & 0xFF, DevInfo.FirmwareVersion & 0xFFFF);
                printf("\tHardware Version:v%d.%d.%d\n", (DevInfo.HardwareVersion >> 24) & 0xFF,
                       (DevInfo.HardwareVersion >> 16) & 0xFF, DevInfo.HardwareVersion & 0xFFFF);
                printf("\tFirmware Functions:%s\n", FunctionStr);
//            printf("\tDev Functions:%d\n", DevHandle[0]);
                return DevHandle;
            }
            return nullptr;
        }

        /**
        * @brief 初始化CAN通讯
        * @param None
        * @retval None
        */
        void canInit() {
            CANConfig.CAN_Mode = 0;//正常模式
            CANConfig.CAN_ABOM = 0;//禁止自动离线
            CANConfig.CAN_NART = 1;//禁止报文重传
            CANConfig.CAN_RFLM = 0;//FIFO满之后覆盖旧报文
            CANConfig.CAN_TXFP = 1;//发送请求决定发送顺序
            //配置波特率,波特率 = 100M/(BRP*(SJW+BS1+BS2))
            CANConfig.CAN_BRP = 25;
            CANConfig.CAN_BS1 = 2;
            CANConfig.CAN_BS2 = 1;
            CANConfig.CAN_SJW = 1;
            int ret;
            ret = CAN_Init(DevHandle[0],CANIndex,&CANConfig);
            if(ret != CAN_SUCCESS){
                LOG(FATAL)<<"Config CAN failed!\n";
            }else{
                printf("Config CAN Success!\n");
            }
            //配置过滤器，必须配置，否则可能无法收到数据

            CANFilter.Enable = 1;
            CANFilter.ExtFrame = 0;
            CANFilter.FilterIndex = 0;
            CANFilter.FilterMode = 0;
            CANFilter.MASK_IDE = 0;
            CANFilter.MASK_RTR = 0;
            CANFilter.MASK_Std_Ext = 0;
            CAN_Filter_Init(DevHandle[0],CANIndex,&CANFilter);

        }

        /**
        * @brief 接收CAN消息
        * @param None
        * @retval None
        */
        void canReadMsg() {
            CAN_MSG CanMsgBuffer[2048];
            isDJIFdb = false;
            int CanNum = CAN_GetMsg(DevHandle[0],0,CanMsgBuffer);
            if( CanNum > 0 ){
                for(int n = 0 ; n < CanNum ; n ++ ){
                    for(int i=0; i<8;i++){
                        // DJI motor decode
                        if (CanMsgBuffer[n].ID == 0x201+i)
                        {
                            if(Motors[i].msg_cnt++ < 50){
                                Motors[i].getRotorOffset(CanMsgBuffer[0].Data);
                            }else
                            {
                                Motors[i].canDataDecoder(CanMsgBuffer[0].Data);
                            }
                            isDJIFdb =true;
                            break;
                        }
                        //TODO: VESC CAN decode
                    }
                    if(!isDJIFdb){// Raw of vesc publish
                        vesc_can_id = CanMsgBuffer[n].ID;
                        LOG(INFO)<<vesc_can_id;
                        for(int i = 0 ; i < 8 ; i ++)
                            vesc_can_msg[i] = CanMsgBuffer[n].Data[i];

                    }
                    // Odom 解析
                    if(!isDJIFdb && (CanMsgBuffer[n].ID == odom.can_id[0] || CanMsgBuffer[n].ID == odom.can_id[1]) ){
                        odom.setEncoderFromCan(CanMsgBuffer[n]);
                    }

                }

            }
            else if(CanNum == 0){
                //        LOG(WARNING)<<"No CAN data!\n";
            }
            else{
                LOG(ERROR)<<"Get CAN data error!\n";
            }

        }


        void upDateMotors(uint32_t can_id, uint8_t *msg, int type){
            if(type == DJI){
                if(can_id == 0x300 ){
                    for(int i = 0 ;i < 4 ; i ++){
                        Motors[i].mode = msg[2 * i + 1];
                        Motors[i].type = msg[2 * i];
                    }
                }
                else if( can_id == 0x302){
                    for(int i = 0 ;i < 4 ; i ++){
                        Motors[i+4].mode = msg[2 * i + 1];
                        Motors[i+4].type = msg[2 * i];
                    }
                }
            }

        }
        /**
          * @brief 发送电机电流
          * @param 电机ID号
          * @retval None
          */
        void canTransmit(uint32_t can_id, uint8_t *msg, int type){
            upDateMotors(can_id, msg, type);
            CAN_MSG CanMsg;
            switch (type) {
                case VESC:
                {
//                    LOG(INFO)<<"VESC working!";
                    CanMsg.RemoteFlag = 0;
                    CanMsg.ExternFlag = 1;
                    CanMsg.DataLen = 4;
                    CanMsg.ID = can_id | (CAN_PACKET_SET_RPM<<8);
                    for(int i = 0;i < 4; i++)
                        CanMsg.Data[i] = msg[i];
                    break;
                }
                case DJI:
                {
                    CanMsg.RemoteFlag = 0;
                    CanMsg.ExternFlag = 0;
                    CanMsg.DataLen = 8;
                    CanMsg.ID = can_id;
                    for(int i = 0;i < 8 ; i++)
                        CanMsg.Data[i] = msg[i];
                    break;
                }
                default:{break;}
            }

            int SendedNum = CAN_SendMsg(DevHandle[0],0,&CanMsg,1);
            if(SendedNum >= 0){
//       LOG(INFO)<<"Send success";
            }else{
                LOG(ERROR)<<"Send CAN data failed!\n";
            }
        }

    };



}

#endif //WTR_CAN_MOTOR_CAN_COMMUTE_H
