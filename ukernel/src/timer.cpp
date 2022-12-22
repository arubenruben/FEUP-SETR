#include "timer.h"
#include "scheduler.h"

void timer_init(uint32_t freq)
{
    noInterrupts(); // disable all interrupts

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 62500 / freq;
    TCCR1B |= (1 << WGM12);  // CTC mode
    TCCR1B |= (1 << CS12);   // 256 prescaler
    TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
}