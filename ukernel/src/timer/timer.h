#ifndef _TIMER_H
#define _TIMER_H

#include <Arduino.h>

void timer_init(int freq, void (*timer_func)(void));

#endif