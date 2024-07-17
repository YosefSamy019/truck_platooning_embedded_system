/*
 * master_car.c
 *
 * Created: 2024-07-08 2:08:53 AM
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
#include "TIMER_2/TIMER2_interface.h"
#include "SPI/SPI_interface.h"

#include "MOTOR/MOTOR.h"

#define C_FORWARD 'F'
#define C_BACKWARD 'B'
#define C_STOP 'S'

#define C_RIGHT 'R'
#define C_LEFT 'L'
#define C_NO_ROTATE 'N'

enum motion curMotion = stop;
enum motion curRotate = noRotate;

void SPI_receive(uint8 c);

void main(){
		//leds
		DIO_pinMode(PIN_A0,OUTPUT);
		DIO_pinMode(PIN_A1,OUTPUT);
		DIO_pinMode(PIN_A2,OUTPUT);
		DIO_pinMode(PIN_A3,OUTPUT);
	
		DIO_digitalWrite(PIN_A0, HIGH);
		DIO_digitalWrite(PIN_A1, HIGH);
		
		DIO_digitalWrite(PIN_A2,HIGH);
		DIO_digitalWrite(PIN_A3,HIGH);
	_delay_ms(1000);
	
	TIMER0_init();
	GI_voidEnable();
	SPI_init();
	UART_init();
	TIMER0_setDutyCycle(30);
	TIMER1_init();
	//TIMER2_init();
	
	SPI_setCallback(SPI_receive);
	
	while(1){
		MOTOR_setMotion(curMotion);
		MOTOR_setRotate(curRotate);
		
		
		DIO_digitalWrite(PIN_A0, curMotion == forward);
		DIO_digitalWrite(PIN_A1, curMotion == backward);
		
		DIO_digitalWrite(PIN_A2, curRotate == right && curMotion != stop);
		DIO_digitalWrite(PIN_A3, curRotate == left && curMotion != stop);
		
		
	}
	
}

void SPI_receive(uint8 c){
	if(c == C_FORWARD || c == (C_FORWARD + 32) ){
		curMotion = forward;
	}
	else if(c == C_BACKWARD || c == (C_BACKWARD + 32)){
		curMotion = backward;
	}
	else if(c == C_STOP || c == (C_STOP + 32)){
		curMotion = stop;
	}
	
	else if(c == C_RIGHT || c == (C_RIGHT + 32)){
		curRotate = right;
	}else if(c == C_LEFT || c == (C_LEFT + 32)){
		curRotate = left;
	}else if(c == C_NO_ROTATE || c == (C_NO_ROTATE + 32)){
		curRotate = noRotate;
	}else{
		//nothig
	}
	uint8 arr[] = {c,'\0'};
	UART_sendStr(arr);
}