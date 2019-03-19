/**
 File:		character.h
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Character function prototypes.
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "location.h"
//Struct of type character
//We are pretending this is a class
typedef struct PlayerCharacter
{
	char *name;
	int MaxHHealth;
	int CurrHealth;
	int AttackPower;
	int DefensePower;
	int currLocation;

}PCharacter;

//"Constructors"
PCharacter* create_character(char *name);

//Accessors
void display_character_stats(PCharacter* currCharacter);
void look_around(location* currLocation);

//Modifiers
void change_location(PCharacter* currCharacter, int newLocation);

//Functions


#endif // !CHARACTER_H