#include <stdio.h>
#include "scryfall_request_card_data.h"




int main(int argc, char *argv[])
{
    	printf("test.c:\n");    
	int result = 0;	

	if(argc > 1)
	{
		char *input = argv[1];
		int result = scryfall_request_card_data(input);

	}else{
		printf("Missing card name");
	}
    	char *cardname = "zurgo%20stormrender";

    	return result;
}
