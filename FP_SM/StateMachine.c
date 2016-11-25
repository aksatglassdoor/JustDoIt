#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>



// This enum defines the valid states for the state machine
typedef enum
{
	STATE_A,
	STATE_B,
	STATE_C,
	STATE_D,
	NUM_STATES
}StateType;

// This structure is used for state machine table
// i.e., fir eash state there is an associated function
// only a pointer to the function is used
// later an array can be created for each state that holds-
// 	both state and function 
typedef struct
{
	StateType State;
	void (*func) (void);
}StateMachineType;


// SM State function declarations
void sm_StateA();
void sm_StateB();
void sm_StateC();
void sm_StateD();

void sm_run();

// Structure array table alluded earlier
StateMachineType StateMachine[]=
{
       {  STATE_A, sm_StateA  },
       {  STATE_B, sm_StateB  },
       {  STATE_C, sm_StateC  },
       {  STATE_D, sm_StateD  }
};

StateType currentState = STATE_A;

int main()
{
	printf("Inside main()\n");
	sm_run();
	printf("\nExiting main()");
}

void sm_run()
{
	char c;
	fflush(stdout);
	while(1){
		sleep(3);
		//scanf("%c",&c);
		if(c=='q')
			break;
		(*StateMachine[currentState].func)();
	}
	return;
}

void sm_StateA(){
	printf("Inside A\n");
	fflush(stdout);
	currentState = STATE_B;
}
void sm_StateB(){
	printf("Inside B\n");
	fflush(stdout);
	currentState = STATE_C;
}
void sm_StateC(){
	printf("Inside C\n");
	fflush(stdout);
	currentState = STATE_D;
}
void sm_StateD(){
	printf("Inside D\n");
	fflush(stdout);
	currentState = STATE_A;
}
