#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdbool.h>

#include "game_state.h"
#include "state_stack.h"

typedef struct STATEMACHINE
{
	state_stack* states;
	game_state* new_state;
	bool is_removing;
	bool is_adding;
	bool is_replacing;
}state_machine;

void add_state(state_machine* curr_machine, game_state* new_state, bool isReplacing);
void remove_state();

void process_state_changes();

game_state* get_active_state();

#endif
