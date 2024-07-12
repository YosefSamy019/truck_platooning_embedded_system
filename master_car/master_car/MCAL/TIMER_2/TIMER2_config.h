/*
 * TIMER2_config.h
 *
 * Created: 2024-02-04 1:06:24 AM
 *  Author: asus
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_



//Calculations of CTC & NORMAL
#define TIMER2_PRELOAD_VAL (0)		//NORMAL OR CTC
#define TIMER2_MAX_COUNT 1			//NORMAL OR CTC
#define TIMER2_COMPARE_VALUE 26	//CTC Only

//Timer/Counter Mode of Operation
#define TIMER2_MODE_NORMAL 0
#define TIMER2_MODE_PHASE_CORRECT 1
#define TIMER2_MODE_CTC 2
#define TIMER2_MODE_FAST_PWM 3
#define TIMER2_MODE_SELECT TIMER2_MODE_CTC

//Compare Output Mode           				//NORMAL/CTC		 F-PWM												 Phase-correct
#define TIMER2_OC2_MODE_0 0						//discounted		 discounted										     discounted
#define TIMER2_OC2_MODE_1 1						//toggle on compare  reserved										     reserved
#define TIMER2_OC2_MODE_2 2						//clear on compare   clear on compare,set at bottom(nin-inverted)        clear count-up,set count-down
#define TIMER2_OC2_MODE_3 3						//set on compare	 set on compare,clear at bottom(inverted)            set count-up, clear count-down
#define TIMER2_OC2_SELECT TIMER2_OC2_MODE_1

//Clock Select Bit Description
#define TIMER2_PRESCALER_NO_CLOCK 0
#define TIMER2_PRESCALER_1 1
#define TIMER2_PRESCALER_8 2
#define TIMER2_PRESCALER_32 3
#define TIMER2_PRESCALER_64 4
#define TIMER2_PRESCALER_128 5
#define TIMER2_PRESCALER_256 6
#define TIMER2_PRESCALER_1024 7
#define TIMER2_PRESCALER_SELECT TIMER2_PRESCALER_8


#endif /* TIMER2_CONFIG_H_ */