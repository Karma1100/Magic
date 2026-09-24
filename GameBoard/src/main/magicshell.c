#include <unistd.h>
#include <stdio.h>




int main()
{
	write(STDOUT_FILENO, "Hi, welcome to the Magic Terminal.\n", 35);
	
	char buffer[100];
	int EXIT_CONDITION = 0;
	for(;;)
	{	
		EXIT_CONDITION = 0;
		write(STDOUT_FILENO, "m_shell>",8);
		ssize_t read_status = read(STDIN_FILENO, buffer, sizeof(buffer));
		
		if(read_status > -1 && buffer[read_status - 1] == '\n')
		{
			buffer[read_status - 1] == '\0';
			EXIT_CONDITION = 1;
			write(STDOUT_FILENO, "input is: ", 10);
			write(STDOUT_FILENO, buffer, (sizeof(buffer) -1));
			//write(STDOUT_FILENO, "\n", 1);
		}
		//this is to check if input is working. Commented out for trouble shooting later
		/*
		if(read_status > -1)
		{
			write(STDOUT_FILENO, "something was wrong, try again\n", 31);
			EXIT_CONDITION = 1;	
		}
		*/		

		if(EXIT_CONDITION = 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, "exit condition met\n", 19); 
			break;
		}
	}
}
