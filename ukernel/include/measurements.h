#pragma once

#include <Arduino.h>
#include "constants.h"

typedef struct
{
    unsigned long start;
    unsigned long end;

} measurement;

typedef struct
{
    uint16_t size;
    measurement vec[MEASUREMENTS_SIZE];

} measure_vec;

extern measure_vec measurements;

void init_measurements();

void add_measure(unsigned long measurement);

void print_measures();