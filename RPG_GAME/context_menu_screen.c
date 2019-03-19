/**
 File:		main_menu_screen.c
 Coder:		Esteban Lopez
 Date:		January, 2019
 Purpose:	Handle the menu system
			will update itself according to 
			where the player is located
*/

#include <stdio.h>

#include "context_menu_screen.h"

void print_menu()
{
	printf("MAIN MENU\n");
	printf("1) START GAME\n");
	printf("2) LOAD GAME\n");
	printf("3) QUIT GAME\n");
}

void print_intro()
{
	printf("You just woke up in the middle of the forest.\n");
	printf("You don't know how you got there or who you are.\n");
	printf("There is a monster close by.\n");
}

void print_in_game_menu()
{
	printf("What do you want to do?\n");
	printf("1) EXPLORE\n");
	printf("2) GO TO\n");
	printf("3) ITEM\n");
	printf("4) QUIT GAME\n");
}