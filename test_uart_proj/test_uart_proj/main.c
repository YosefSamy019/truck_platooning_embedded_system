/*
 * test_uart_proj.c
 *
 * Created: 2024-07-17 7:08:56 PM
 * Author : asus
 */ 

#define F_CPU 16000000UL

#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD -1)


#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/UART/UART_Bluetooth.h"

#include "HAL/LCD/LCD.h"


void uartISR(u8 c){
	/*SET_BIT(PORTD,3);
	lcd_send_data('$');
	lcd_send_data(c);
	_delay_ms(10);
	CLEAR_BIT(PORTD,3);*/
	
	lcd_set_cursor(0,0);
	lcd_clear();
	lcd_send_data(c);
}

int main(void)
{
	
	sei();
	
	UART_init();
	lcd_init();
	
	CLR_BIT(DDRB,0);
	SET_BIT(DDRC,2);
	SET_BIT(DDRD,3);
	SET_BIT(PORTC,2);

	lcd_send_str("UART TESTER");
	UART_sendStr("Send Test");
	_delay_ms(2000);
	
	lcd_clear();
	lcd_set_cursor(0,0);
	
	UART_onReceive(uartISR);
	
    while (1) 
    {
		
		if(GET_BIT(PINB,0)==1){
			lcd_clear();
			lcd_set_cursor(0,0);
			SET_BIT(PORTC,2);
		}
		CLR_BIT(PORTC,2);

    }
	
}

