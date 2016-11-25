#include <stdio.h>
#include <stdint.h>
#include "mySchedular.h"
#include <time.h>
#include <unistd.h>

static TypeTask tasks[] =
{
	{0, 			0,	tsk_idle},
	{1*CLOCKS_PER_SEC,	0,	tsk_1s},
	{5*CLOCKS_PER_SEC,	0,	tsk_5s},
	{10*CLOCKS_PER_SEC,	0,	tsk_10s}
};


uint8_t GetNumberOfTasks(){
	return (sizeof(tasks)/sizeof(tasks[0]));
}



int main(){
	uint8_t num, curr_task;
	num = GetNumberOfTasks();
	printf("Number of tasks-%d\n", num);
	while(1){	
		for(curr_task=0 ; curr_task < num; curr_task++){
			if(tasks[curr_task].interval==0)
				(*tasks[curr_task].task_func)();
			else{
				if(((clock()- tasks[curr_task].last_time)) > 								tasks[curr_task].interval){
					(*tasks[curr_task].task_func)();
					tasks[curr_task].last_time = clock();
				}
			}
		}
	}
}



void tsk_idle(){}//{printf("Idle Task\n");fflush(stdout);}
void tsk_1s(){printf("1sec Task\n");fflush(stdout);}
void tsk_5s(){printf("\t5sec Task\n");fflush(stdout);}
void tsk_10s(){printf("\t\t10sec Task\n");fflush(stdout);}



