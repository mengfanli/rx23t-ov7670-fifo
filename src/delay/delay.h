/*
 * delay.h
 *
 *  Created on: Jul 27, 2017
 *      Author: Arthur
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_

#include <stdint.h>
#include "../cg_src/r_cg_macrodriver.h"

extern void CMT1_Init(void);
extern void delayms(uint16_t time);
extern void CMT1_IntHandler(void);
extern void delay_ms(int ms);
extern void delay_us(int us);

#endif /* DELAY_DELAY_H_ */
