/**
 File:		game.h
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Game logic function prototypes.
*/

#ifndef GAME_H
#define GAME_H
#include <stdbool.h>

#include "game_state.h"

//Game struct to store game related variables
//We are pretending this is a class
typedef struct GAME_STRUCT
{
	int choice;
	bool quit;
	GameState currState;
}Game;

//This is our "constructor"
Game* init_game();

//Accessors
bool get_quit(Game* gameInstance);

//Modifiers
void set_quit(Game* gameInstance);

//Functions
void boot_game(Game* gameInstance);
void start_adventure();
void update(Game* gameInstance);

//Helper Functions
void process_player_input(Game* gameInstance);
int check_for_int();
char* check_for_string();

#endif // !GAME_H
