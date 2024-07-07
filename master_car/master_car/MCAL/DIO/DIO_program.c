/*
 * DIO_program.c
 *
 * Created: 2024-02-12 5:19:03 PM
 *  Author: asus
 */ 
#include <avr/io.h> 

#include "BIT_MATH.h"

#include "DIO_interface.h"

void DIO_pinMode(char PIN_NO,char DIR){
	char pin,port;
	pin =  PIN_NO & 0x0f;
	port = PIN_NO & 0xf0;
	
	switch(DIR){
		case OUTPUT:
		switch (port){
			case A:SET_BIT(DDRA,pin); break;
			case B:SET_BIT(DDRB,pin); break;
			case C:SET_BIT(DDRC,pin); break;
			case D:SET_BIT(DDRD,pin); break;
		}
		break;
		case INPUT:
		switch (port){
			case A:CLR_BIT(DDRA,pin); break;
			case B:CLR_BIT(DDRB,pin); break;
			case C:CLR_BIT(DDRC,pin); break;
			case D:CLR_BIT(DDRD,pin); break;
		}
		break;
	}
}

void DIO_digitalWrite(char PIN_NO,char STATE){
	char pin,port;
	pin =  PIN_NO & 0x0f;
	port = PIN_NO & 0xf0;
	
	switch(STATE){
		case HIGH:
		switch (port){
			case A:SET_BIT(PORTA,pin); break;
			case B:SET_BIT(PORTB,pin); break;
			case C:SET_BIT(PORTC,pin); break;
			case D:SET_BIT(PORTD,pin); break;
		}
		break;
		case LOW:
		switch (port){
			case A:CLR_BIT(PORTA,pin); break;
			case B:CLR_BIT(PORTB,pin); break;
			case C:CLR_BIT(PORTC,pin); break;
			case D:CLR_BIT(PORTD,pin); break;
		}
		break;
	}
}

char DIO_digitalRead(char PIN_NO){
	char pin,port;
	pin =  PIN_NO & 0x0f;
	port = PIN_NO & 0xf0;
	
	switch (port){
		case A:return GET_BIT(PINA,pin); break;
		case B:return GET_BIT(PINB,pin); break;
		case C:return GET_BIT(PINC,pin); break;
		case D:return GET_BIT(PIND,pin); break;
	}
}
