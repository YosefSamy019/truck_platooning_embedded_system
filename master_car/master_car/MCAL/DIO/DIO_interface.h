/*
 * DIO_interface.h
 *
 * Created: 2024-02-12 5:19:38 PM
 *  Author: asus
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PIN_A0 0xA0
#define PIN_A1 0xA1
#define PIN_A2 0xA2
#define PIN_A3 0xA3
#define PIN_A4 0xA4
#define PIN_A5 0xA5
#define PIN_A6 0xA6
#define PIN_A7 0xA7

#define PIN_B0 0xB0
#define PIN_B1 0xB1
#define PIN_B2 0xB2
#define PIN_B3 0xB3
#define PIN_B4 0xB4
#define PIN_B5 0xB5
#define PIN_B6 0xB6
#define PIN_B7 0xB7

#define PIN_C0 0xC0
#define PIN_C1 0xC1
#define PIN_C2 0xC2
#define PIN_C3 0xC3
#define PIN_C4 0xC4
#define PIN_C5 0xC5
#define PIN_C6 0xC6
#define PIN_C7 0xC7

#define PIN_D0 0xD0
#define PIN_D1 0xD1
#define PIN_D2 0xD2
#define PIN_D3 0xD3
#define PIN_D4 0xD4
#define PIN_D5 0xD5
#define PIN_D6 0xD6
#define PIN_D7 0xD7

#define HIGH 1
#define LOW  0

#define OUTPUT 1
#define INPUT  0

#define A 0xA0
#define B 0xB0
#define C 0xC0
#define D 0xD0


void DIO_pinMode(char PIN_NO,char DIR);
void DIO_digitalWrite(char PIN_NO,char STATE);
char DIO_digitalRead(char PIN_NO);

#endif /* DIO_INTERFACE_H_ */