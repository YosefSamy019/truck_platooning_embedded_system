/*
 * SPI_private.h
 *
 * Created: 2024-02-08 1:38:53 PM
 *  Author: asus
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"


#define SPCR_REG (*((volatile uint8*)0x2D))
#define SPSR_REG (*((volatile uint8*)0x2E))
#define SPDR_REG (*((volatile uint8*)0x2F))

//PINS
#define SPI_SS_PIN   PIN_B4
#define SPI_MOSI_PIN PIN_B5
#define SPI_MISO_PIN PIN_B6
#define SPI_SCK_PIN  PIN_B7


#endif /* SPI_PRIVATE_H_ */