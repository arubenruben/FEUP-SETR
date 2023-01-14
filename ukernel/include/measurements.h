#pragma once

#include <Arduino.h>
#include "constants.h"

#ifdef MEASUREMENTS
void init_measurements();
void start_measure(unsigned long measurement);
void end_measure(unsigned long measurement);
#endif