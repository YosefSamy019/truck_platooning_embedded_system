/*
 * Timer0_PWM.c
 *
 * Created: 7/10/2024 4:57:14 PM
 *  Author: Mahmoud Osman
 */ 
#include "TIMER_0/Timer0_PWM.h"

void TIMER0_init(void){
	DIO_pinMode(PIN_B3,OUTPUT);
	//DIO_pinMode(PIN_B4,OUTPUT);
	//DIO_digitalWrite(PIN_B4,HIGH);
	//SET TO FAST PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//select non inverting mode
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	
	//set prescaller to 1024
	
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
}


void TIMER0_setDutyCycle(uint8 speed){
	uint8 OCR_Val= speed*2.55;
	OCR0=OCR_Val;
	
	
	
}