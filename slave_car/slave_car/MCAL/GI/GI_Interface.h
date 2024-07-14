/*
 * GI_Interface.h
 *
 * Created: 9/30/2023 6:19:06 AM
 *  Author: ok
 */ 


#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

#define SREG       *((volatile uint8*)0x5F)
#define SPEG_I  7

void GI_voidEnable(void);

void GI_voidDisable(void);





#endif /* GI_INTERFACE_H_ */