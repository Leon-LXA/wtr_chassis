/**
  ******************************************************************************
  * @file    usb2pwm.h
  * $Author: wdluo $
  * $Revision: 447 $
  * $Date:: 2013-06-29 18:24:57 +0800 #$
  * @brief   usb2pwm��غ������������Ͷ���.
  ******************************************************************************
  * @attention
  *
  *<center><a href="http:\\www.toomoss.com">http://www.toomoss.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
#ifndef __USB2PWM_H_
#define __USB2PWM_H_

#include <stdint.h>
#ifndef OS_UNIX
#include <Windows.h>
#else
#include <unistd.h>
#ifndef WINAPI
#define WINAPI
#endif
#endif

//�����ʼ��PWM����������
typedef struct _PWM_CONFIG{
  unsigned short Prescaler[8];  //Ԥ��Ƶ��
  unsigned short Precision[8];  //ռ�ձȵ��ھ���,ʵ��Ƶ�� = 200MHz/(Prescaler*Precision)
  unsigned short Pulse[8];      //ռ�ձȣ�ʵ��ռ�ձ�=(Pulse/Precision)*100%
  unsigned char  Polarity[8];   //���μ��ԣ�ȡֵ0����1
  unsigned char  ChannelMask;   //ͨ���ţ���Ҫʹ��ĳ��ͨ�������ӦλΪ1�����λ��Ӧͨ��0
}PWM_CONFIG,*PPWM_CONFIG;

//���庯�����ش������
#define PWM_SUCCESS             (0)   //����ִ�гɹ�
#define PWM_ERR_NOT_SUPPORT     (-1)  //��������֧�ָú���
#define PWM_ERR_USB_WRITE_FAIL  (-2)  //USBд����ʧ��
#define PWM_ERR_USB_READ_FAIL   (-3)  //USB������ʧ��
#define PWM_ERR_CMD_FAIL        (-4)  //����ִ��ʧ��

#ifdef __cplusplus
extern "C"
{
#endif

int WINAPI PWM_Init(int DevHandle, PPWM_CONFIG pConfig);
int WINAPI PWM_Start(int DevHandle,unsigned char ChannelMask,unsigned int RunTimeUs);
int WINAPI PWM_SetPulse(int DevHandle,unsigned char ChannelMask,unsigned short *pPulse);
int WINAPI PWM_SetPhase(int DevHandle,unsigned char ChannelMask,unsigned short *pPhase);
int WINAPI PWM_SetFrequency(int DevHandle,unsigned char ChannelMask,unsigned short *pPrescaler,unsigned short *pPrecision);
int WINAPI PWM_Stop(int DevHandle,unsigned char ChannelMask);

#ifdef __cplusplus
}
#endif
#endif
