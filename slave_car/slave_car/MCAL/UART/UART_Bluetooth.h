/*
 * UART_Bluetooth.h
 *
 * Created: 2024-07-12 2:53:42 PM
 *  Author: asus
 */ 


#ifndef UART_BLUETOOTH_H_
#define UART_BLUETOOTH_H_


#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"

void UART_init(void);
void UART_sendStr(uint8 str[]);
void UART_onReceive(void (*ptr2fun)(uint8 c));



#endif /* UART_BLUETOOTH_H_ */