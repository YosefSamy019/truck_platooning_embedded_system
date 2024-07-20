#include "UART_Bluetooth.h"

#define F_CPU 16000000UL

#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD -1)

volatile void (*UART_receiveCallback)(uint8 c) = 0;

void UART_init(void) {
	unsigned int ubrr = MYUBRR;
	unsigned int ubrrH = (uint8)(ubrr >> 8);
	
	// Enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);
	
	// Set frame format: 8 data bits, 1 stop bit
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0);
	
	// Set baud rate
	UBRRH = (uint8)ubrrH;
	UBRRL = (uint8)ubrr;
	

	


}

void UART_sendStr(u8 str[]) {
	int i = 0;
	while (str[i] != '\0') {
		while (!(UCSRA & (1 << UDRE)));  // Wait until buffer is empty
		UDR = str[i];                     // Put data into buffer, sends the data
		i++;
	}
}

void UART_onReceive(void (*ptr2fun)(u8)) {
	UART_receiveCallback = ptr2fun;
	// Enable the UART Receive Complete interrupt
	UCSRB |= (1 << RXCIE);
}

ISR(USART_RXC_vect) {
	if (UART_receiveCallback) {
		u8 receivedChar = (u8)UDR;  // Read the received data
		UART_receiveCallback(receivedChar);  // Call the user-defined function
	}
}
