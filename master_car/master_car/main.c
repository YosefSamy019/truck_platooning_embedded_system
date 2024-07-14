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

void c(char c){
	UART_sendStr("A");
		PORTA ^= 1;

}

/*
void main(){
		DIO_pinMode(PIN_A0,OUTPUT);


		DIO_pinMode(PIN_D7,OUTPUT);
		//TIMER2_init();
		
		SET_BIT(SREG,7);

	UART_init();
	
	UART_onReceive(c);	
	
	while(1){
		_delay_ms(2000);
	}
	
	

	
}

*/

void main(){
			GI_voidEnable();

					DIO_pinMode(PIN_A0,OUTPUT);

		
	SPI_init();
	//MOTOR_init();
	//TIMER0_init();
	//
	//MOTOR_setMotion(stop);
	//MOTOR_setRotate(noRotate);
	//MOTOR_setDutyCycle(50);
	//
	SPI_setCallback(c);
	
	UART_init();
	UART_sendStr("HI");
	//UART_onReceive(c);

	while(1){
		static uint8 i=0;
		//SPI_transceive(i++);
		

	}
}


/*
void isr(){
	static int i=0;
	
	if(i){
		DIO_digitalWrite(PIN_A0,LOW);
	}else{
				DIO_digitalWrite(PIN_A0,HIGH);
	}
	i=~i;
}

int main(void)
{
	
	SET_BIT(SREG,7);
	
		DIO_pinMode(PIN_A0,OUTPUT);
TIMER1_init();
TIMER1_setCallBack(isr);
	
    while (1) 
    {
    }
}

*/