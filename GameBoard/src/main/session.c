#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

//only playing jumpstart, so there is a max of 2 players
#define PLAYER_ONE 0;
#define PlAYER_TWO 1;



//**
//
//
int game_shell_loop()
{
	char *line;
	char **args;
	int player_turn;



	int status = 1;
	do
	{
		printf("MagicBoard -> ");

		line = read_input_line();

		args = parse_line();
		//status = execute_command(args);
		free(line);
		free(args)

	}while(status);	





	return 0;
}
