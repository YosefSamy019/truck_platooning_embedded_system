/*
 * TIMER2_private.h
 *
 * Created: 2024-02-04 1:06:09 AM
 *  Author: asus
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define TIMER2_TICKS_NO 256  //2^resolution, 2^8 = 256

#define OC2_PIN PIN_D7

#define TCCR2_REG *((volatile uint8*)0x45)
#define TCNT2_REG *((volatile uint8*)0x44)
#define OCR2_REG  *((volatile uint8*)0x43)
#define TIMSK_REG *((volatile uint8*)0x59)



#endif /* TIMER2_PRIVATE_H_ */