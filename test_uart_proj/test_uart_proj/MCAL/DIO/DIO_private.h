/*
 * DIO_private.h
 *
 * Created: 2024-01-26 6:49:03 PM
 *  Author: asus
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

//addresses of registers of A,B,C,D which can be accessed by C-level

#define DDRA_REG *((volatile u8*)0x3A)
#define DDRB_REG *((volatile u8*)0x37)
#define DDRC_REG *((volatile u8*)0x34)
#define DDRD_REG *((volatile u8*)0x31)

#define PORTA_REG *((volatile u8*)0x3B)
#define PORTB_REG *((volatile u8*)0x38)
#define PORTC_REG *((volatile u8*)0x35)
#define PORTD_REG *((volatile u8*)0x32)

#define PINA_REG *((volatile u8*)0x39)
#define PINB_REG *((volatile u8*)0x36)
#define PINC_REG *((volatile u8*)0x33)
#define PIND_REG *((volatile u8*)0x30)



#endif /* DIO_PRIVATE_H_ */