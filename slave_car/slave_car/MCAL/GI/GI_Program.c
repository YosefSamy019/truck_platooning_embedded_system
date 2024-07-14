/*
 * GI_Program.c
 *
 * Created: 9/30/2023 6:18:41 AM
 *  Author: ok
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GI_Interface.h"




void GI_voidEnable(void)
{
	SET_BIT(SREG,SPEG_I);
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG,SPEG_I);
	
}