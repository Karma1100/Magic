#include <stdio.h>
#include "scryfall_request_card_data.h"




int main()
{
    printf("test.c:\n");    

    char *cardname = "zurgo%20stormrender";

    int result = scryfall_request_card_data(cardname);

    return 1;
}