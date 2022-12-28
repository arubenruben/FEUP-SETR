#include "measurements.h"

measure_vec measurements;

void init_measurements()
{
    measurements.size = 0;

    for (size_t i = 0; i < MEASUREMENTS_SIZE; i++)
    {
        measurements.vec[i].start = 0;
        measurements.vec[i].end = 0;
    }
}

void add_measure(unsigned long measurement)
{
    if (measurements.vec[measurements.size].start == 0)
    {
        measurements.vec[measurements.size].start = measurement;
    }
    else
    {
        measurements.vec[measurements.size].end = measurement;
        measurements.size++;
    }

    if (measurements.size == MEASUREMENTS_SIZE)
    {
        print_measures();
    }
}

void print_measures()
{
    noInterrupts();

    Serial.println("End Execution 100 Measurments Reached. Print Then Exit");
    Serial.println("------------------");

    Serial.print("Begin(ms)");
    Serial.print("\t");
    Serial.print("End(ms)");
    Serial.print("\n");

    for (size_t i = 0; i < MEASUREMENTS_SIZE; i++)
    {
        Serial.print(measurements.vec->start);
        Serial.print("\t");
        Serial.print(measurements.vec->start);
        Serial.print("\n");
    }

    Serial.println("------------------");

    exit(0);
}