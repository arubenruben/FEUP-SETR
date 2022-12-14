#include "timer.h"

void init_timer()
{
    noInterrupts();

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 62500; // compare match register 16MHz/256/2Hz
    // OCR1A = 31;               // compare match register 16MHz/256/2kHz
    TCCR1B |= (1 << WGM12);  // CTC mode
    TCCR1B |= (1 << CS12);   // 256 prescaler
    TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

    interrupts();
}