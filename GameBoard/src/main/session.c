#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



int game_shell_loop()
{
	char *line;
	char **args;

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
