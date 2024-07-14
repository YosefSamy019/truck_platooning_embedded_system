/*
 * slave_car.c
 *
 * Created: 2024-07-08 2:19:01 AM
 * Author : asus
 */ 
#include <avr/io.h>

#define F_CPU 16000000UL
#include <avr/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_0/Timer0_PWM.h"
#include "TIMER_1/timer1.h"
#include "DIO/DIO_interface.h"
#include "UART/UART_Bluetooth.h"

#include "MOTOR/MOTOR.h"


void c(char c){
	static uint8 i=0;
	
	MOTOR_setDutyCycle(30);
	if(i){
	MOTOR_setMotion(forward);
	MOTOR_setRotate(noRotate);
	}else{
		MOTOR_setMotion(backward);
		MOTOR_setRotate(noRotate);
	}
	i=~i;
}

int main(void)
{
	GI_voidEnable();
	MOTOR_init();
	
	UART_init();
	UART_onReceive(c);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

