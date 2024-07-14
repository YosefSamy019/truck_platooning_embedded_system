/*
 * SPI_interface.h
 *
 * Created: 2024-02-08 1:38:38 PM
 *  Author: asus
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

void SPI_init(void);

#if SPI_MODE==SPI_MASTER_MODE||SPI_MODE==SPI_SLAVE_MODE
	uint8 SPI_transceive(uint8 data);
#endif

#if SPI_ENABLE_INTERRUPT==1||SPI_MODE==SPI_SLAVE_MODE
	void SPI_setCallback(func_uint8_ptr fptr);
#endif

#endif /* SPI_INTERFACE_H_ */