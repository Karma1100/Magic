#include <stdio.h>
#include <unistd.h>


#ifdef _WIN32
	#include <windows.h>
#else
	#include <sys/wait.h>
#endif
#include <string.h>

//only playing jumpstart, so there is a max of 2 players
#define PLAYER_ONE 0;
#define PlAYER_TWO 1;

//session will create the ground for the game. Manager will call session to create a new gameboard
/*
Manger calls session -> 
session creates gameboard by calling gamestate, rules and phases/phase check



*/
