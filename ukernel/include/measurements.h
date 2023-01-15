#pragma once

#include <Arduino.h>
#include "constants.h"

#ifdef MEASUREMENTS
void init_measurements();
void start_measure(unsigned long measurement);
void end_measure(unsigned long measurement);
void print_measures();

#define INIT_MEASUREMENTS() init_measurements()
#define START_MEASURE() start_measure(micros())
#define END_MEASURE() end_measure(micros())

#else
#define INIT_MEASUREMENTS()
#define START_MEASURE()
#define END_MEASURE()
#endif