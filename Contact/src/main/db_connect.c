#include <libpq-fe.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



int main()
{
	write(STDOUT_FILENO, "Data Base Connect script\n",25);
	const char *conninfo = "host = 127.0.0.1 port = 5432 dbname = magic_cards user = host1 password = pass";
	
	PGconn *conn = PQconnectdb(conninfo);

	if (PQstatus(conn) != CONNECTION_OK) 
	{
        	fprintf(stderr, "Connection failed: %s\n", PQerrorMessage(conn));
        	PQfinish(conn);
        	return 1;
    	}

    	write(STDOUT_FILENO, "Connected to database\n", 22);

	
	
	PQfinish(conn);
	write(STDOUT_FILENO, "Connection ended\n", 17);

	return 0;
}

