/*
 * TIMER2_interface.c
 *
 * Created: 2024-02-04 1:05:44 AM
 *  Author: asus
 */ 

#include "TIMER2_interface.h"
#include <avr/interrupt.h>
#include <avr/io.h>


void TIMER2_init(void){
	#if TIMER2_MODE_SELECT == TIMER2_MODE_NORMAL
		//Normal Mode
		CLR_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(TIMER2_OC2_SELECT<<4);
	
		//PRELOAD VALUE
		TCNT2_REG = TIMER2_PRELOAD_VAL;
	
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(TIMER2_PRESCALER_SELECT);

		// Timer/Counter2 Overflow Interrupt Enable
		SET_BIT(TIMSK_REG,6);
	
	#elif TIMER2_MODE_SELECT == TIMER2_MODE_CTC
		//CTC Mode
		SET_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(TIMER2_OC2_SELECT<<4);
	
		//PRELOAD VALUE
		TCNT2_REG = TIMER2_PRELOAD_VAL;
		
		//COMPARE VALUE
		OCR2_REG = TIMER2_COMPARE_VALUE;
			
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(TIMER2_PRESCALER_SELECT);

		// Timer/Counter2 Output Compare Match Interrupt Enable
		//SET_BIT(TIMSK_REG,7);
	
	#elif TIMER2_MODE_SELECT == TIMER2_MODE_FAST_PWM
		//FAST PWM
		SET_BIT(TCCR2_REG,6);
		SET_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(TIMER2_OC2_SELECT<<4);
	
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(TIMER2_PRESCALER_SELECT);
	
		//OC2 OUTPUT
		DIO_pinMode(OC2_PIN,OUTPUT);
	
	#elif TIMER2_MODE_SELECT == TIMER2_MODE_PHASE_CORRECT
		//Phase Correct
		SET_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(TIMER2_OC2_SELECT<<4);
	
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(TIMER2_PRESCALER_SELECT);
	
		//OC2 OUTPUT
		DIO_pinMode(OC2_PIN,OUTPUT);
	#else
	#error TIMER2 error, mode operation undefined
	#endif
}

#if TIMER2_MODE_SELECT == TIMER2_MODE_NORMAL || TIMER2_MODE_SELECT == TIMER2_MODE_CTC
static ptr2fun callback = NULL;
void TIMER2_setCallback(ptr2fun fptr){
	callback = fptr;
}
#endif

//Timer/Counter2 Overflow ISR
#if TIMER2_MODE_SELECT == TIMER2_MODE_NORMAL
	void __vector_5(void)__attribute__((signal));
	void __vector_5(){
		static uint32 counter = 0;
		counter++;

		if(counter == TIMER2_MAX_COUNT){
			counter = 0;
			TCNT2_REG = TIMER2_PRELOAD_VAL;
			
			if(callback != NULL){
				callback();
			}
			
		}
	}
#endif


//Timer/Counter2 Compare ISR
#if TIMER2_MODE_SELECT == TIMER2_MODE_CTC
	
	
	ISR(TIMER2_COMP_vect){
		static uint32 counter = 0;
		counter++;

		if(counter == TIMER2_MAX_COUNT){
			counter = 0;
			TCNT2_REG = TIMER2_PRELOAD_VAL;
			
			if(callback != NULL){
				callback();
			}
			
		}
	}
	
#endif

#if TIMER2_MODE_SELECT == TIMER2_MODE_FAST_PWM || TIMER2_MODE_SELECT == TIMER2_MODE_PHASE_CORRECT
	//dutyCycle range [0.0, 1.0]
	void TIMER2_setDutyCucle(float32 dutyCycle){
		uint8 ocrValue = 0;
	
		#if TIMER2_OC2_SELECT == TIMER2_OC2_MODE_2     //nin inverted mode
			ocrValue = (uint8)(dutyCycle * (TIMER2_TICKS_NO - 1));
		#elif TIMER2_OC2_SELECT == TIMER2_OC2_MODE_3   //inverted mode
			ocrValue = (uint8)((1.0 - dutyCycle) * (TIMER2_TICKS_NO - 1));
		#else
			#error TIMER2 ERROR, in PWM or Phase correct, the oc2 must be inverted or nin inverted
		#endif
	
		OCR2_REG = ocrValue;
	}

#endif