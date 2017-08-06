#ifndef _OV7670_H
#define _OV7670_H

#include <stdint.h>
#include "../cg_src/r_cg_port.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ο�������guanfu_wang���롣
//ALIENTEKս��STM32������V3
//OV7670 ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/18
//�汾��V1.0		    							    							  
//////////////////////////////////////////////////////////////////////////////////
 
#define OV_WIDTH	320
#define OV_HEIGHT	240
#define OV7670_VSYNC  	PORTE.PIDR.BIT.B2		//同步信号检测IO
#define OV7670_WRST		PORT3.PODR.BIT.B0		//写指针复位
#define OV7670_WREN		PORT3.PODR.BIT.B1		//写入FIFO使能 低有效）
//#define OV7670_OREN		PORTD.PODR.BIT.B4		//FIFO输出使能端口 低有效
#define OV7670_OREN		PORT3.PODR.BIT.B3		//Output Enable
#define OV7670_RCK_H	PORT0.PODR.BIT.B0=1		//设置读数据时钟高电平 read clock
#define OV7670_RCK_L	PORT0.PODR.BIT.B0=0		//设置读数据时钟低电平
#define OV7670_RRST		PORT3.PODR.BIT.B2  		//读指针复位
#define OV7670_CS		PORT3.PODR.BIT.B3 		//片选信号(OE//Output Enable


#define OV7670_DATA   	PORT4.PIDR.BYTE  		//数据输入端口
/////////////////////////////////////////									
void R_FIFO_Create(void);
void R_FIFO_Write_Reset(void);
void R_FIFO_Read_Reset(void);
uint8_t   OV7670_Init(void);
void OV7670_Light_Mode(uint8_t mode);
void OV7670_Color_Saturation(uint8_t sat);
void OV7670_Brightness(uint8_t bright);
void OV7670_Contrast(uint8_t contrast);
void OV7670_Special_Effects(uint8_t eft);
void OV7670_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void OV7670_config_window(uint16_t startx,uint16_t starty,uint16_t width, uint16_t height);


#endif





















