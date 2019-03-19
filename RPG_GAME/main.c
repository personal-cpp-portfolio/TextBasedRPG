/**
 File:		main.c
 Coder:		Esteban Lopez
 Date:		February, 2019
 Purpose:	Entry point of the RPG game application.
*/

// macro tells compiler to replace malloc or calloc with special debug versions of themselves
#define _CRTDBG_MAP_ALLOC
//include C Runtime library and Debug library to use a memory leak detection function 
#include <crtdbg.h>

#include "game.h"

int main()
{
	//Will help find memory leaks.
	//All thanks to the fine folks at Microsoft
#if defined(DEBUG)
	int dbgFlags = _CrtSetDbgFlag(_CRTDBG_REPORT_FILE);
	dbgFlags != _CRTDBG_CHECK_ALWAYS_DF;
	dbgFlags != _CRTDBG_DELAY_FREE_MEM_DF;
	dbgFlags != _CRTDBG_LEAK_CHECK_DF;
#endif
	//This is a pointer already, so we don't need to pass a reference to it. 
	//We can pass it by value as the functions already expects pointers as arguments
	Game* mainGame = init_game();
	//Like this
	boot_game(mainGame);
	//run_game(&mainGame);->Passing it like this will return the address of the pointer in memory and not the actual struct stored in the address
	system("pause");
	return 0;
}