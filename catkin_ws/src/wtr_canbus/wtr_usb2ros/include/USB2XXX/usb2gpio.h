/**
  ******************************************************************************
  * @file    usb2gpio.h
  * $Author: wdluo $
  * $Revision: 447 $
  * $Date:: 2013-06-29 18:24:57 +0800 #$
  * @brief   usb2gpio��غ������������Ͷ���.
  ******************************************************************************
  * @attention
  *
  *<center><a href="http:\\www.toomoss.com">http://www.toomoss.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
#ifndef __USB2GPIO_H_
#define __USB2GPIO_H_

#include <stdint.h>
#ifndef OS_UNIX
#include <Windows.h>
#else
#include <unistd.h>
#ifndef WINAPI
#define WINAPI
#endif
#endif


//���庯�����ش������
#define GPIO_SUCCESS             (0)   //����ִ�гɹ�
#define GPIO_ERR_NOT_SUPPORT     (-1)  //��������֧�ָú���
#define GPIO_ERR_USB_WRITE_FAIL  (-2)  //USBд����ʧ��
#define GPIO_ERR_USB_READ_FAIL   (-3)  //USB������ʧ��
#define GPIO_ERR_CMD_FAIL        (-4)  //����ִ��ʧ��

//��������������
#define GPIO_PUPD_NOPULL        0x00    //û����������
#define GPIO_PUPD_UP            0x01    //ʹ������
#define GPIO_PUPD_DOWN          0x02    //ʹ������

#ifdef __cplusplus
extern "C"
{
#endif
/**
  * @brief  ��GPIO��������Ϊ����ģʽ
  * @param  DevHandle �豸������
  * @param  PinMask ��Ҫ����Ϊ����ģʽ�����ţ�ÿ��bitλ����һ�����ţ���ӦbitλΪ1ʱ�����Ŷ�������Ч�����λΪP0
  * @param  PuPd 0-�������룬����������������1-�������룬2-��������
  * @retval ����ִ��״̬��С��0����ִ�г���
  */
int WINAPI GPIO_SetInput(int DevHandle,unsigned int PinMask, unsigned char PuPd);
/**
  * @brief  ��GPIO��������Ϊ���ģʽ
  * @param  DevHandle �豸������
  * @param  PinMask ��Ҫ����Ϊ���ģʽ�����ţ�ÿ��bitλ����һ�����ţ���ӦbitλΪ1ʱ�����Ŷ�������Ч�����λ��ӦP0
  * @param  PuPd 0-�������������������������1-���������2-�������
  * @retval ����ִ��״̬��С��0����ִ�г���
  */
int WINAPI GPIO_SetOutput(int DevHandle,unsigned int PinMask, unsigned char PuPd);
/**
  * @brief  ��GPIO��������Ϊ��©ģʽ����ģʽ�¿���Ϊ˫������
  * @param  DevHandle �豸������
  * @param  PinMask ��Ҫ����Ϊ��©ģʽ�����ţ�ÿ��bitλ����һ�����ţ���ӦbitλΪ1ʱ�����Ŷ�������Ч�����λ��ӦP0
  * @param  PuPd 0-�ڲ�����������������1-ʹ��������2-ʹ������
  * @retval ����ִ��״̬��С��0����ִ�г���
  */
int WINAPI GPIO_SetOpenDrain(int DevHandle,unsigned int PinMask, unsigned char PuPd);
/**
  * @brief  ����GPIO���ŵ����״̬
  * @param  DevHandle �豸������
  * @param  PinMask ��Ҫ���״̬�����ţ�ÿ��bitλ����һ�����ţ���ӦbitλΪ1ʱ�����Ŷ�������Ч�����λ��ӦP0
  * @param  PinValue ��Ӧ���ŵ�״̬��ÿ��bitλ����һ�����ţ���ӦbitλΪ1����ߵ�ƽ��Ϊ0����͵�ƽ�����λ��ӦP0
  * @retval ����ִ��״̬��С��0����ִ�г���
  */
int WINAPI GPIO_Write(int DevHandle,unsigned int PinMask, unsigned int PinValue);
/**
  * @brief  ��ȡGPIO���ŵ�����״̬
  * @param  DevHandle �豸������
  * @param  PinMask ��Ҫ��ȡ״̬�����ţ�ÿ��bitλ����һ�����ţ���ӦbitλΪ1ʱ�����Ŷ�������Ч�����λ��ӦP0
  * @param  pPinValue ��Ӧ���ŵ�״̬��ÿ��bitλ����һ�����ţ���ӦbitλΪ1����Ϊ�ߵ�ƽ��Ϊ0����Ϊ�͵�ƽ�����λ��ӦP0
  * @retval ����ִ��״̬��С��0����ִ�г���
  */
int WINAPI GPIO_Read(int DevHandle,unsigned int PinMask, unsigned int *pPinValue);

#ifdef __cplusplus
}
#endif

#endif

