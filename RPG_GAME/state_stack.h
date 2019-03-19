#ifndef STATE_STACK_H
#define STATE_STACK_H

#include "game_state.h"



typedef struct STATESTACK
{
	game_state * top;
	int size;
}state_stack;

state_stack* init_stack();
bool isEmpty(state_stack* statesADT);
void push_back(state_stack* statesADT, game_state newState);
int pop_back();

#endif
