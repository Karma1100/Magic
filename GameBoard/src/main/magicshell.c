#include <unistd.h>
#include <stdio.h>




int main()
{
	write(STDOUT_FILENO, "Hi, welcome to the Magic Terminal.\n", 35);
	
	char buffer[100];
	int EXIT_CONDITION = 0;
	for(;;)
	{
		write(STDOUT_FILENO, "m_shell>",8);
		

		if(EXIT_CONDITION != 1)
		{
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, "exit condition met\n", 19); 
			break;
		}
	}
}
