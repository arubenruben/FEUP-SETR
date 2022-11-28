#pragma once

#include <Arduino.h>

void timer_init(int freq, void (*timer_func)(void));
