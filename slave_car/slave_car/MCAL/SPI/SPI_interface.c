/*
 * SPI_interface.c
 *
 * Created: 2024-02-08 1:38:23 PM
 *  Author: asus
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SPI_interface.h"

void SPI_init(void){
	//SPI enable
	SET_BIT(SPCR_REG,6);
	
	//Data order
	#if SPI_DATA_ORDER_SELECT == SPI_DATA_ORDER_MSB_IS_FIRST
		CLR_BIT(SPCR_REG,5);
	#elif SPI_DATA_ORDER_SELECT == SPI_DATA_ORDER_LSB_IS_FIRST
		SET_BIT(SPCR_REG,5);
	#else
		#error SPI ERROR, Data order not defined
	#endif
	
	//Clock Polarity
	SPCR_REG = (SPCR_REG&(0b11110111)) | (SPI_CLOCK_POLARITY_SELECT<<3);
	
	//Clock Phase
	SPCR_REG = (SPCR_REG&(0b11111011)) | (SPI_CLOCK_PHASE_SELECT<<2);
	
	//SPI mode
	#if SPI_MODE == SPI_SLAVE_MODE
				//slave select
				CLR_BIT(SPCR_REG,4);
	
		//pins directions
		DIO_pinMode(SPI_MOSI_PIN,INPUT);
		DIO_pinMode(SPI_MISO_PIN,OUTPUT);
		DIO_pinMode(SPI_SS_PIN,INPUT);
		DIO_pinMode(SPI_SCK_PIN,INPUT);
		
		//interrupt enable
		SPCR_REG = (SPCR_REG&0b01111111)|(SPI_ENABLE_INTERRUPT<<7);
		

				
	#elif SPI_MODE == SPI_MASTER_MODE
		//Prescaler
		//SPR0, SPR1 bits
		SPCR_REG = (SPCR_REG&0b11111100)|(SPI_PRESCALER_SELECT&0b00000011);
		//SPI2X: Double SPI Speed Bit
		SPSR_REG = (SPSR_REG&0b11111110)|(SPI_PRESCALER_SELECT>>2);
		
		//pins directions
		DIO_pinMode(SPI_MOSI_PIN,OUTPUT);
		DIO_pinMode(SPI_MISO_PIN,INPUT);
		DIO_pinMode(SPI_SS_PIN,OUTPUT);
		DIO_pinMode(SPI_SCK_PIN,OUTPUT);

		//unselected the slave (active low)
		DIO_digitalWrite(SPI_SS_PIN,HIGH);
		
		
		//master select, should be after make the SS output according to datasheet
		SET_BIT(SPCR_REG,4);

	#else
		 #error SPI ERROR, Mode not defined
	#endif
}

#if SPI_MODE==SPI_MASTER_MODE
	uint8 SPI_transceive(uint8 data){
		//select the slave active low
		DIO_digitalWrite(SPI_SS_PIN,LOW);
	
		SPDR_REG = data;
	
		//wait
		while(GET_BIT(SPSR_REG,7)==0);
	
		//unselect the slave active low
		DIO_digitalWrite(SPI_SS_PIN,HIGH);
	
		return ((uint8)SPDR_REG);
	}
#endif
#if SPI_MODE==SPI_SLAVE_MODE
uint8 SPI_transceive(uint8 data){
	
	SPDR_REG = data;
	//wait
	uint32 i = 0;
	while(GET_BIT(SPSR_REG,7)==0 && i<1000){
		i++;
	}
	
	if(i==1000) return 0;
	else return ((uint8)SPDR_REG);
}
#endif

#if SPI_ENABLE_INTERRUPT==1||SPI_MODE==SPI_SLAVE_MODE
	static volatile func_uint8_ptr callback = NULL;
	
	void SPI_setCallback(func_uint8_ptr fptr){
		callback = fptr;
	}
	
	ISR(SPI_STC_vect) {
		if(callback != NULL){
			callback((uint8)SPDR_REG);
		}
	}
	

#endif