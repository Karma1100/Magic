#include <unistd.h>
#include <stdio.h>




int main()
{
	write(STDOUT_FILENO, "Hi, welcome to the Magic Terminal.\n", 35);
	
	char buffer[100];

	for(;;)
	{
		write(STDOUT_FILENO, "m_shell>",8);
		

	}
}
