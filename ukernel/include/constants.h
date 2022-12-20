#pragma once

#define MAX_TASKS 4
#define TASK_STACK_SIZE 100

#define BAUD_RATE 9600
#define DEFAULT_FREQ 20

#define TASK_STATE_IDLE 0
#define TASK_STATE_RUNNING 1
#define TASK_STATE_BLOCKED 2

#define D1 13
#define D2 12
#define D3 11
#define D4 10

#define MUTEX_LOCK 0
#define MUTEX_UNLOCK 1
#define N_MUTEXES 2