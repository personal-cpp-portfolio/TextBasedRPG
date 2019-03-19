/**
 File:		game.c
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Header file to describe the what is possible in a particular location
*/

#ifndef LOCATION_H
#define LOCATION_H

typedef struct LOCATION
{
	const char *description;
	const char *tag;
}location;

//"Constructors"
location* create_locations();

//Accessors


//Modifiers


//Functions

#endif