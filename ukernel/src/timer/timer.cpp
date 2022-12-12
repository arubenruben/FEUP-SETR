#include "timer.h"

ISR(TIMER1_COMPA_vect)
{
    
}

void initialize_timer(int freq)
{
    noInterrupts(); // disable all interrupts

    // timer_func = func;

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 62500 / freq;
    TCCR1B |= (1 << WGM12);  // CTC mode
    TCCR1B |= (1 << CS12);   // 256 prescaler
    TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

    interrupts(); // enable all interrupts
}