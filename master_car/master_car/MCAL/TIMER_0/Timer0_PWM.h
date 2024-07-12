/*
 * Timer0_PWM.h
 *
 * Created: 7/10/2024 4:57:24 PM
 *  Author: Mahmoud Osman
 */ 


#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_
#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO/DIO_interface.h"

void TIMER0_init(void);
void TIMER0_setDutyCycle(uint8 speed);



#endif /* TIMER0_PWM_H_ */