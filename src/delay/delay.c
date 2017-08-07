/*
 * delay.c
 *
 *  Created on: Jul 27, 2017
 *      Author: Arthur
 */
#include "delay.h"

uint8_t time_flag = 0;
uint16_t time_count = 0;

void CMT0_Init(void)
{
    R_CMT0_Start();
}

void delayms(uint16_t time)
{
    time_flag = 1;
    while(time_count != time);
    time_flag = 0;
    time_count = 0;
}
void delay_ms(int ms)
{
	int i;
	int a = ms*10000;
	for(i = 0;i<a;i++);
}
void delay_us(int us)
{
	int i;
	int a = us*10;
	for(i = 0;i<a;i++);
}

