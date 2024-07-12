#ifndef TIMER1_ATMEGA16_H
#define TIMER1_ATMEGA16_H

#include <avr/io.h>
#include <avr/interrupt.h>

// Registers
#define TCCR1A   (*((volatile uint8_t*)0x4F))
#define TCCR1B   (*((volatile uint8_t*)0x4E))
#define TCNT1    (*((volatile uint16_t*)0x4C))
#define OCR1A    (*((volatile uint16_t*)0x4A))
#define TIMSK    (*((volatile uint8_t*)0x59))

// Macros
#define TIMER1_PRESCALER_1      0b001
#define TIMER1_PRESCALER_8      0b010
#define TIMER1_PRESCALER_64     0b011
#define TIMER1_PRESCALER_256    0b100
#define TIMER1_PRESCALER_1024   0b101

#define TIMER1_NORMAL_MODE   0b00
#define TIMER1_CTC_MODE      0b01

// Function Prototypes
void TIMER1_init(void);
void TIMER1_setCallBack(void (*ptr2fun)());

#endif // TIMER1_ATMEGA16_H