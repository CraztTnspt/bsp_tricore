/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		uart
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC364DP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/
 
#ifndef _zf_uart_h
#define _zf_uart_h


#include "common.h"
#include "ifxAsclin_Asc.h"



#define UART0_TX_BUFFER_SIZE 128//���崮��0���ͻ�������С
#define UART0_RX_BUFFER_SIZE 16	//���崮��0���ջ�������С

#define UART1_TX_BUFFER_SIZE 128
#define UART1_RX_BUFFER_SIZE 16

#define UART2_TX_BUFFER_SIZE 128
#define UART2_RX_BUFFER_SIZE 16

#define UART3_TX_BUFFER_SIZE 128
#define UART3_RX_BUFFER_SIZE 16



//��ö�ٶ��岻�����û��޸�
typedef enum //ö�ٴ��ں�
{
    UART_0,
    UART_1,
    UART_2,
    UART_3,
}UARTN_enum;


//��ö�ٶ��岻�����û��޸�
typedef enum //ö�ٴ�������
{
	//����0 �������ſ�ѡ��Χ
	UART0_TX_P14_0, UART0_TX_P14_1,  UART0_TX_P15_2,  UART0_TX_P15_3,
	//����0 �������ſ�ѡ��Χ
	UART0_RX_P14_1, UART0_RX_P15_3,

	//��LQFP144��װ��û��P14_10��P14_8
	//����1 �������ſ�ѡ��Χ
	UART1_TX_P02_2, UART1_TX_P11_12, UART1_TX_P14_10, UART1_TX_P15_0, UART1_TX_P15_1,  UART1_TX_P15_4,  UART1_TX_P15_5, UART1_TX_P20_10, UART1_TX_P33_12, UART1_TX_P33_13,
	//����1 �������ſ�ѡ��Χ
	UART1_RX_P02_3, UART1_RX_P11_10, UART1_RX_P14_8,  UART1_RX_P15_1, UART1_RX_P15_5,  UART1_RX_P20_9,  UART1_RX_P33_13,

	//����2 �������ſ�ѡ��Χ
	UART2_TX_P02_0, UART2_TX_P10_5,  UART2_TX_P14_2,  UART2_TX_P14_3, UART2_TX_P33_8,  UART2_TX_P33_9,
	//����2 �������ſ�ѡ��Χ
	UART2_RX_P02_0, UART2_RX_P02_1,  UART2_RX_P10_6,  UART2_RX_P14_3, UART2_RX_P33_8,

	//��LQFP144��װ��û��P32_2��P32_3
	//����3 �������ſ�ѡ��Χ
	UART3_TX_P00_0, UART3_TX_P00_1,  UART3_TX_P15_6,  UART3_TX_P15_7, UART3_TX_P20_0,  UART3_TX_P20_3,  UART3_TX_P21_7, UART3_TX_P32_2,  UART3_TX_P32_3,
	//����3 �������ſ�ѡ��Χ
	UART3_RX_P00_1, UART3_RX_P15_7,  UART3_RX_P20_3,  UART3_RX_P21_6, UART3_RX_P32_2,
}UART_PIN_enum;



//��������handle����
extern IfxAsclin_Asc uart0_handle;
extern IfxAsclin_Asc uart1_handle;
extern IfxAsclin_Asc uart2_handle;
extern IfxAsclin_Asc uart3_handle;

void uart_init(UARTN_enum uartn, uint32 baud, UART_PIN_enum tx_pin, UART_PIN_enum rx_pin);
void uart_putchar(UARTN_enum uartn, uint8 dat);
void uart_putbuff(UARTN_enum uartn, uint8 *buff, uint32 len);
void uart_putstr(UARTN_enum uartn, const int8 *str);
void uart_getchar(UARTN_enum uartn, uint8 *dat);
uint8 uart_query(UARTN_enum uartn, uint8 *dat);
void finSH_uart_init(void);

#endif
