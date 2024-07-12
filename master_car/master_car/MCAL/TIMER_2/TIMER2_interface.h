/*
 * TIMER2_interface.h
 *
 * Created: 2024-02-04 1:05:37 AM
 *  Author: asus
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "TIMER2_config.h"
#include "TIMER2_private.h"

void TIMER2_init(void);

#if TIMER2_MODE_SELECT == TIMER2_MODE_NORMAL || TIMER2_MODE_SELECT == TIMER2_MODE_CTC
void TIMER2_setCallback(ptr2fun fptr);
#endif

#if TIMER2_MODE_SELECT == TIMER2_MODE_FAST_PWM || TIMER2_MODE_SELECT == TIMER2_MODE_PHASE_CORRECT
//dutyCycle range [0.0, 1.0]
void TIMER2_setDutyCucle(float32 dutyCycle);
#endif


#endif /* TIMER2_INTERFACE_H_ */