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
#include "SPI/SPI_interface.h"

#include "MOTOR/MOTOR.h"

#define ROTATE_ARR_SIZE 10

#define C_FORWARD 'F'
#define C_BACKWARD 'B'
#define C_STOP 'S'

#define C_RIGHT 'R'
#define C_LEFT 'L'
#define C_NO_ROTATE 'N'


enum motion curMotion = stop;
enum rotation curRotation = noRotate;
enum rotation futureRotation = noRotate;

void uart_receive(uint8 c);
void timer1_callback(void);

enum rotation rotateWatcher[ROTATE_ARR_SIZE];

uint8 shiftArrFlag = 0;

int main(void)
{
	uint32 i=0;
	while(i<ROTATE_ARR_SIZE){
		rotateWatcher[i] = noRotate;
		i++;
	}
	
	GI_voidEnable();
	TIMER0_init();
	TIMER1_init();
	SPI_init();
	MOTOR_init();
	
	MOTOR_setDutyCycle(30);
	MOTOR_setMotion(curMotion);
	MOTOR_setRotate(curRotation);
	
	TIMER1_setCallBack(timer1_callback);
	SPI_setCallback(uart_receive);
	
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
	
	
	
    while (1) 
    {
		MOTOR_setMotion(curMotion);
		MOTOR_setRotate(curRotation);
		
		DIO_digitalWrite(PIN_A0, curMotion == forward);
		DIO_digitalWrite(PIN_A1, curMotion == backward);
		
		DIO_digitalWrite(PIN_A2, curRotation == right && curMotion != stop);
		DIO_digitalWrite(PIN_A3, curRotation == left && curMotion != stop);
		
		
		
		if(shiftArrFlag > 0){
			curRotation = rotateWatcher[ROTATE_ARR_SIZE - 1];
			
			//shift
			uint32 i;
			for(i = ROTATE_ARR_SIZE-1 ; i>0; i--){
				rotateWatcher[i] = rotateWatcher[i - 1];
			}
			
			rotateWatcher[0] = futureRotation;
			
			shiftArrFlag --;
		}
		
		
    }
}

void uart_receive(uint8 c){
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
		futureRotation = right;
	}else if(c == C_LEFT || c == (C_LEFT + 32)){
		futureRotation = left;
	}else if(c == C_NO_ROTATE || c == (C_NO_ROTATE + 32)){
		futureRotation = noRotate;
	}else{
		//nothig
	}
}

void timer1_callback(void){
	//call each 50 milli

	if(curMotion == stop){
		curRotation = noRotate;
	}else{
		shiftArrFlag ++;
	}
	
}