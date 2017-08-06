#ifndef __SCCB_H
#define __SCCB_H
#include <stdint.h>
#include "../delay/delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ο�������guanfu_wang���롣
//ALIENTEKս��STM32������V3
//SCCB ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/18
//�汾��V1.0		    							    							  
//////////////////////////////////////////////////////////////////////////////////
  
#define SCCB_SDA_IN()  PORT0.PDR.BIT.B2=0
#define SCCB_SDA_OUT() PORT0.PDR.BIT.B2=1

//IO��������	 
#define SCCB_SCL    		PORT0.PODR.BIT.B1	 	//SCL
#define SCCB_SDA    		PORT0.PODR.BIT.B2 		//SDA

#define SCCB_READ_SDA    	PORT0.PIDR.BIT.B2  		//输入SDA
#define SCCB_ID   			0X42  					//OV7670的ID

///////////////////////////////////////////
void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
uint8_t SCCB_WR_Byte(uint8_t dat);
uint8_t SCCB_RD_Byte(void);
uint8_t SCCB_WR_Reg(uint8_t reg,uint8_t data);
uint8_t SCCB_RD_Reg(uint8_t reg);
#endif













