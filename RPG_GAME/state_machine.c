#include "state_machine.h"


void add_state(state_machine* curr_machine, game_state* new_state, bool isReplacing)
{
	curr_machine->is_adding = true;
	curr_machine->is_replacing = isReplacing;

	curr_machine->new_state = new_state;
}

