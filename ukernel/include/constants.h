#pragma once

#define MAX_PRIORITY INT8_MAX

#define MAX_TASKS 8
#define TASK_STACK_SIZE 100

#define BAUD_RATE 9600
#define DEFAULT_PERIOD 5 // ms

#define TASK_STATE_IDLE 0
#define TASK_STATE_RUNNING 1
#define TASK_STATE_BLOCKED 2

#define D1 13
#define D2 12
#define D3 11
#define D4 10

#define NUM_MAX_LEDS 5

#define MUTEX_UNLOCKED 0
#define MUTEX_LOCKED 1
#define N_MUTEXES 2

#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

#define BUZZER_DIO 3

#define MEASUREMENTS_SIZE 50