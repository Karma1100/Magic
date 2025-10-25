#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


/*
 *Need to be appended to the end of the api url. Spaces do not need to be accounted for as http will deal with it
 */
char *formatting_url(char *url, char *card)
{


        int url_len = strlen(url) + strlen(card) + 1;
        char *new_url = (char *)malloc(url_len * sizeof(char));
        if(new_url == NULL)
        {
                perror("Shit did not work(new url)");
                return NULL;
        }
        strcpy(new_url, url);
        strcat(new_url, card);

        return new_url;
}




int scryFall_request_card_data(char *card_name)
{
	CURL *curl = curl_easy_init();
	CURLcode res;

	char *base_url = "https://api.scryfall.com/cards/named?fuzzy=";
	
	char *request_url = formatiing_url(base_url, card_name);

	if(curl)
        {
                //Header init
                struct curl_slist *headers = NULL;

                headers = curl_slist_append(headers, "Accept: application/json");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

                //User Agent init

                curl_easy_setopt(curl, CURLOPT_USERAGENT, "AI Project Beta (ajdefafa@gmail.com)");

                //Url Call
                curl_easy_setopt(curl, CURLOPT_URL, request_url);
                res = curl_easy_perform(curl);


                //free
                curl_easy_cleanup(curl);
                curl_slist_free_all(headers);

        }

	if(request_url != NULL)
	{
		free(request_url);
	}

        if(res != CURLE_OK) {
            fprintf(stderr, "Connection failed: %s\n", curl_easy_strerror(res));
            return 1;
        }
        if(res == CURLE_OK)
        {
                printf("Connection and transfer successful!\n");
                return 0;
        }
	
	



}


