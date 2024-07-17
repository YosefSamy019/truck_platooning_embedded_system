/*
 * DIO_interface.h
 *
 * Created: 2024-01-26 6:48:49 PM
 *  Author: asus
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "DIO_private.h"

//PROTOTYPES
void DIO_setPinVal(u8 pin,boolean value);
void DIO_setPinDir(u8 pin,u8 dir);
boolean DIO_readPin(u8 pin);
void DIO_togglePin(u8 pin);

void DIO_setNippleVal(u8 nipple,u8 value);
void DIO_setNippeDir(u8 nipple,u8 dir);
u8   DIO_readNipple(u8 nipple);

void DIO_setPortVal(u8 port_dio,u8 value);
void DIO_setPortDir(u8 port_dio,u8 dir);
u8   DIO_readPort(u8 port_dio);


//direction
#define DIR_INPUT         0x00
#define DIR_OUTPUT		  0x01
#define DIR_INPUT_PULL_UP 0x02

//PINS MACROS
#define PIN_A0 ((u8)0x00)
#define PIN_A1 ((u8)0x01)
#define PIN_A2 ((u8)0x02)
#define PIN_A3 ((u8)0x03)
#define PIN_A4 ((u8)0x04)
#define PIN_A5 ((u8)0x05)
#define PIN_A6 ((u8)0x06)
#define PIN_A7 ((u8)0x07)

#define PIN_B0 ((u8)0x10)
#define PIN_B1 ((u8)0x11)
#define PIN_B2 ((u8)0x12)
#define PIN_B3 ((u8)0x13)
#define PIN_B4 ((u8)0x14)
#define PIN_B5 ((u8)0x15)
#define PIN_B6 ((u8)0x16)
#define PIN_B7 ((u8)0x17)

#define PIN_C0 ((u8)0x20)
#define PIN_C1 ((u8)0x21)
#define PIN_C2 ((u8)0x22)
#define PIN_C3 ((u8)0x23)
#define PIN_C4 ((u8)0x24)
#define PIN_C5 ((u8)0x25)
#define PIN_C6 ((u8)0x26)
#define PIN_C7 ((u8)0x27)

#define PIN_D0 ((u8)0x30)
#define PIN_D1 ((u8)0x31)
#define PIN_D2 ((u8)0x32)
#define PIN_D3 ((u8)0x33)
#define PIN_D4 ((u8)0x34)
#define PIN_D5 ((u8)0x35)
#define PIN_D6 ((u8)0x36)
#define PIN_D7 ((u8)0x37)

//NIPPLES MACROS
#define NIPPLE_A_HIGH ((u8)0x01)
#define NIPPLE_A_LOW  ((u8)0x00)

#define NIPPLE_B_HIGH ((u8)0x11)
#define NIPPLE_B_LOW  ((u8)0x10)

#define NIPPLE_C_HIGH ((u8)0x21)
#define NIPPLE_C_LOW  ((u8)0x20)

#define NIPPLE_D_HIGH ((u8)0x31)
#define NIPPLE_D_LOW  ((u8)0x30)

//PORTS MACROS
#define PORT_A_DIO ((u8)0x00)
#define PORT_B_DIO ((u8)0x01)
#define PORT_C_DIO ((u8)0x02)
#define PORT_D_DIO ((u8)0x03)


#endif /* DIO_INTERFACE_H_ */