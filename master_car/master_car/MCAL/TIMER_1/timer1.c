#include "timer1.h"
#include "STD_TYPES.h"


static void (*timer1_callback)() = NULL;

void TIMER1_init(void) {
    // Set Timer1 to CTC/normal mode
    TCCR1A = 0x00;
    TCCR1B = (1 << WGM12) | (TIMER1_PRESCALER_256 & 0b111);

    // Set Timer1 compare value for 50 ms interrupt
    OCR1A = 3125;

    // Enable Timer1 compare interrupt
    TIMSK |= (1 << OCIE1A);
}

void TIMER1_setCallBack(void (*ptr2fun)()) {
    timer1_callback = ptr2fun;
}

// Timer1 ISR (every 50 ms)
ISR(TIMER1_COMPA_vect) {
    if (timer1_callback != NULL) {
        timer1_callback();
    }
}