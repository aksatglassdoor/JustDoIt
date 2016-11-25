#ifndef HEADERDILE_mySchedular
#define HEADER_FILE_mySchedular

#include <stdint.h>
#include <time.h>

typedef struct{
	clock_t interval;
	clock_t last_time;
	void (*task_func)(void);
}TypeTask;



void tsk_idle(void);
void tsk_1s(void);
void tsk_5s(void);
void tsk_10s(void);
uint8_t GetNumberOfTasks(void);



#endif
