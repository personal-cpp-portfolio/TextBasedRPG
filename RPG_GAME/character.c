/**
 File:		game.c
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Defines everything the character can do such as
			-Fight
			-Item
			-Magic
			-Escape
*/
#include <stdlib.h>
#include <stdio.h>
#include "character.h"
#include "location.h"

/************************************************************************/
/*"CONSTRUCTOR"                                                         */
/************************************************************************/
PCharacter* create_character(char *name)
{
	PCharacter *new_character = (PCharacter*)malloc(sizeof(PCharacter));
	new_character->name = name;
	new_character->MaxHHealth = 10;
	new_character->CurrHealth = new_character->MaxHHealth;
	new_character->AttackPower = 5;
	new_character->DefensePower = 5;
	new_character->currLocation = 0;

	return (new_character);
}

/************************************************************************/
/*ACCESSORS                                                             */
/************************************************************************/
void display_character_stats(PCharacter* currCharacter)
{
	printf("Name: %s\n",currCharacter->name);
	printf("Health: %d/%d\n", currCharacter->CurrHealth, currCharacter->MaxHHealth);
	printf("Attack: %d\n",currCharacter->AttackPower);
	printf("Defense: %d\n", currCharacter->DefensePower);
}

/************************************************************************/
/*MODIFIERS                                                             */
/************************************************************************/
void change_location(PCharacter* currCharacter, int newLocation)
{
	currCharacter->currLocation = newLocation;
}
/************************************************************************/
/* FUNCTIONS                                                            */
/************************************************************************/
void look_around(location* currLocation)
{
	printf("You are in %s", currLocation->description);
}

/************************************************************************/
/*HELPER FUNCTIONS                                                      */
/************************************************************************/