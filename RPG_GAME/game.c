/**
 File:		game.c
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Handle the logic of the game
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include "context_menu_screen.h"
#include "game.h"
#include "character.h"
#include "Types.h"

/************************************************************************/
/*"CONSTRUCTOR"                                                         */
/************************************************************************/
Game* init_game()
{
	Game* gameInstance = (Game*)malloc(sizeof(Game));
	gameInstance->choice = -1;
	gameInstance->quit = false;
	gameInstance->currState = PLAY;
	return gameInstance;
}

/************************************************************************/
/*ACCESSORS                                                             */
/************************************************************************/
bool get_quit(Game* gameInstance)
{
	return gameInstance->quit;
}

/************************************************************************/
/*MODIFIERS                                                             */
/************************************************************************/
//Lets the game know we want to quit
void set_quit(Game* gameInstance)
{
	gameInstance->quit = true;
}

/************************************************************************/
/* FUNCTIONS                                                            */
/************************************************************************/
//Initializes the game. We can think of this almost as the entry point.
void boot_game(Game* gameInstance)
{
	print_menu();
	while (!get_quit(gameInstance))
	{
		update(gameInstance);
	}
}

//This is when we go pass the main menu. Chapter 1 if you will
void start_adventure()
{
	print_intro();
	printf("Enter a name for your champion: ");
	char *char_name = check_for_string();
	PCharacter *player_character =  create_character(char_name);
	display_character_stats(player_character);
	print_in_game_menu();
}

//Updates states of the game
void update(Game* gameInstance)
{
	process_player_input(gameInstance);
}

/************************************************************************/
/*HELPER FUNCTIONS                                                      */
/************************************************************************/
void process_player_input(Game* gameInstance)
{
	int choice = check_for_int();
	switch (choice)
	{
	case 1:
		printf("Your adventure will start soon\n");
		start_adventure();
		break;
	case 2:
		printf("This feature will come to us soon\n");
		break;
	case 3:
		printf("Exiting the game... good bye\n");
		set_quit(gameInstance);
		break;
	default:
		printf("Sorry, the option you entered is not valid\n");
		break;
	}
}

//Used when an integer needs to be returned
//Will check for invalid input
int check_for_int()
{
	int playerInput = 0;
	char buffer[16];	//How many characters are we allowing to be read
	int success;		//Marks a successful conversion

	do 
	{
		if (!fgets(buffer, 16, stdin))
		{
			//Unable to read input
			return -1;
		}

		//Convert input to integer
		char *endptr;

		errno = 0; //reset error number
		playerInput = strtol(buffer, &endptr, 10);
		if (errno == ERANGE)
		{
			printf("ERROR, Number too small or too large, try again\n");
			success = 0;
		}
		else if (endptr == buffer)
		{
			//No character could be read
			printf("ERROR, no character could be read, try again.\n");
			success = 0;
		}
		else if (*endptr && *endptr != '\n')
		{
			//endptr is not EOF or newline
			//so, whole input was not converted
			printf("ERROR, blank space characters are not supported, try again.\n");
			success = 0;
		}
		else if (playerInput < 1 || playerInput > 3)
		{
			printf("ERROR, Invalid choice, try again\n");
			success = 0;
		}
		else
		{
			success = 1;
		}
	} while (!success);

	return playerInput;
}

//Returns an error message if no input has been entered
//Accepts space in between characters
char* check_for_string()
{
	static char playerInput[15]; //Static helps a function that returns a pointer, retain the data it is returning
	int maxCount = 15;

	if (!fgets(playerInput, maxCount, stdin))
	{
		printf("ERROR, Input could not be read. Exiting the game.\n");
		EXIT_FAILURE;
	}

	return playerInput;
}
