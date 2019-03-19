#ifndef GAME_STATE_H
#define GAME_STATE_H


typedef struct GAME_STATE
{
	struct GAME_STATE currState;
	struct GAME_STATE * next;
}game_state;

void init_state(game_state currState);
void handle_input(game_state currState);
void update_state(game_state currState);
void draw_state(game_state currState);

#endif
