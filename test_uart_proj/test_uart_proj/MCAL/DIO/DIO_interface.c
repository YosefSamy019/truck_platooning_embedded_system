/*
 * DIO_interface.c
 *
 * Created: 2024-01-26 6:47:57 PM
 *  Author: asus
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_setPinVal(u8 pin,boolean value){
	u8 regNo,pinNo;
	
	regNo = GET_HIGH_NIPPLE(pin);
	pinNo = GET_LOW_NIPPLE(pin);
	
	if(regNo < 4 && pinNo < 8){
		switch (regNo)
		{
			case 0: 
				(value == TRUE)? SET_BIT(PORTA_REG,pinNo):CLR_BIT(PORTA_REG,pinNo);
				break;
			case 1:
				(value == TRUE)? SET_BIT(PORTB_REG,pinNo):CLR_BIT(PORTB_REG,pinNo);
				break;
			case 2:
				(value == TRUE)? SET_BIT(PORTC_REG,pinNo):CLR_BIT(PORTC_REG,pinNo);
				break;
			case 3:
				(value == TRUE)? SET_BIT(PORTD_REG,pinNo):CLR_BIT(PORTD_REG,pinNo);
				break;										
		}
	}
}
void DIO_setPinDir(u8 pin,u8 dir){
	u8 regNo, pinNo;
	volatile u8 *regDDR = NULL,*regPORT = NULL;
	
	regNo = GET_HIGH_NIPPLE(pin);
	pinNo = GET_LOW_NIPPLE(pin);
	
	if(regNo < 4 && pinNo < 8){
		switch (regNo)
		{
			case 0:
				regDDR = &DDRA_REG;regPORT = &PORTA_REG; break;
			case 1:
				regDDR = &DDRB_REG;regPORT = &PORTB_REG; break;
			case 2:
				regDDR = &DDRC_REG;regPORT = &PORTC_REG; break;
			case 3:
				regDDR = &DDRD_REG;regPORT = &PORTD_REG; break;
		}
		
		switch (dir)
		{
			case DIR_INPUT:
				CLR_BIT(*regDDR,pinNo);break;
			case DIR_OUTPUT:
				SET_BIT(*regDDR,pinNo);break;
			case DIR_INPUT_PULL_UP:
				CLR_BIT(*regDDR,pinNo);
				SET_BIT(*regPORT,pinNo);break;
		}
		
	}
}

boolean DIO_readPin(u8 pin){
	boolean value = 0;
	u8 regNo,pinNo;
	
	regNo = GET_HIGH_NIPPLE(pin);
	pinNo = GET_LOW_NIPPLE(pin);
	
	if(regNo < 4 && pinNo < 8){
		switch (regNo)
		{
			case 0:
				value = GET_BIT(PORTA_REG,pinNo);break;
			case 1:
				value = GET_BIT(PORTB_REG,pinNo);break;
			case 2:
				value = GET_BIT(PORTC_REG,pinNo);break;
			case 3:
				value = GET_BIT(PORTD_REG,pinNo);break;
		}
	}
	return value;
}
void DIO_togglePin(u8 pin){
		u8 regNo,pinNo;
		
	regNo = GET_HIGH_NIPPLE(pin);
	pinNo = GET_LOW_NIPPLE(pin);
		
		if(regNo < 4 && pinNo < 8){
			switch (regNo)
			{
				case 0:
					TOG_BIT(PORTA_REG,pinNo);break;
				case 1:
					TOG_BIT(PORTB_REG,pinNo);break;
				case 2:
					TOG_BIT(PORTC_REG,pinNo);break;
				case 3:
					TOG_BIT(PORTD_REG,pinNo);break;
			}
		}
}


void DIO_setNippleVal(u8 nipple,u8 value){
	volatile u8* regPort = NULL;
	u8 nippleNo,regNo;
	
	regNo = GET_HIGH_NIPPLE(nipple);
	nippleNo = GET_LOW_NIPPLE(nipple);
	
	if(regNo < 4 && nippleNo < 2){
		switch (regNo)
		{
			case 0:
			regPort = &PORTA_REG; break;
			case 1:
			regPort = &PORTB_REG; break;
			case 2:
			regPort = &PORTC_REG; break;
			case 3:
			regPort = &PORTD_REG; break;
		}
		
		switch(nippleNo){
			case 0:
				(*regPort) = (((*regPort)&0xf0) | ((value & 0x0f))); break;
			case 1:
				(*regPort) = (((*regPort)&0x0f) | ((value<<4)));     break;
		}		
	}
	
}
void DIO_setNippeDir(u8 nipple,u8 dir){
	volatile u8* regDDR = NULL,*regPort = NULL;
	u8 nippleNo,regNo;
	
	regNo = GET_HIGH_NIPPLE(nipple);
	nippleNo = GET_LOW_NIPPLE(nipple);
	
	if(regNo < 4 && nippleNo < 2){
		switch (regNo)
		{
			case 0:
			regPort = &PORTA_REG; regDDR = &DDRA_REG; break;
			case 1:
			regPort = &PORTB_REG; regDDR = &DDRB_REG; break;
			case 2:
			regPort = &PORTC_REG; regDDR = &DDRC_REG; break;
			case 3:
			regPort = &PORTD_REG; regDDR = &DDRD_REG; break;
		}
		
		switch(dir){
			case DIR_INPUT:
				(nippleNo==0)? CLR_LOW_NIPPLE(*regDDR):  CLR_HIGH_NIPPLE(*regDDR);  break;

			case DIR_OUTPUT:
				(nippleNo==0)? SET_LOW_NIPPLE(*regDDR):  SET_HIGH_NIPPLE(*regDDR);  break;
			case DIR_INPUT_PULL_UP:
				(nippleNo==0)? CLR_LOW_NIPPLE(*regDDR):  CLR_HIGH_NIPPLE(*regDDR);
				(nippleNo==0)? SET_LOW_NIPPLE(*regPort): SET_HIGH_NIPPLE(*regPort); 
				break;
		}
	}
	
}
u8 DIO_readNipple(u8 nipple){
	volatile u8* regPin = NULL;
	u8 nippleNo,regNo,returnVal = 0;
	
	regNo = GET_HIGH_NIPPLE(nipple);
	nippleNo = GET_LOW_NIPPLE(nipple);
	
	if(regNo < 4 && nippleNo < 2){
		switch (regNo)
		{
			case 0:
			regPin = &PINA_REG; break;
			case 1:
			regPin = &PINB_REG; break;
			case 2:
			regPin = &PINC_REG; break;
			case 3:
			regPin = &PIND_REG; break;
		}
		
		switch(nippleNo){
			case 0:
			returnVal = GET_LOW_NIPPLE(*regPin); break;
			case 1:
			returnVal = GET_HIGH_NIPPLE(*regPin); break;
		}
	}
	
	return returnVal;
}

void DIO_setPortVal(u8 port_dio,u8 value){
	u8 portNo = GET_LOW_NIPPLE(port_dio);
	
	switch(portNo){
		case 0: PORTA_REG = value; break;
		case 1: PORTB_REG = value; break;
		case 2: PORTC_REG = value; break;
		case 3: PORTD_REG = value; break;
	}
}
void DIO_setPortDir(u8 port_dio,u8 dir){
		u8 portNo = GET_LOW_NIPPLE(port_dio);
		volatile u8 *regDDR=NULL,*regPort=NULL;
		
		if(portNo < 4){
			switch (portNo)
			{
				case 0:
				regPort = &PORTA_REG; regDDR = &DDRA_REG; break;
				case 1:
				regPort = &PORTB_REG; regDDR = &DDRB_REG; break;
				case 2:
				regPort = &PORTC_REG; regDDR = &DDRC_REG; break;
				case 3:
				regPort = &PORTD_REG; regDDR = &DDRD_REG; break;
			}
			switch(dir){
				case DIR_INPUT:         (*regDDR) = 0x00; break;
				case DIR_OUTPUT:		(*regDDR) = 0xff; break;
				case DIR_INPUT_PULL_UP: (*regDDR) = 0x00; (*regPort) = 0xff; break;
			}
		}
}
u8   DIO_readPort(u8 port_dio){
	u8 portNo = GET_LOW_NIPPLE(port_dio);
	u8 returnVal=0;
	
	switch(portNo){
		case 0: returnVal = PINA_REG; break;
		case 1: returnVal = PINB_REG; break;
		case 2: returnVal = PINC_REG; break;
		case 3: returnVal = PIND_REG; break;
	}
	
	return returnVal;
}