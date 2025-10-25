#include <stdio.h>
#include <curl/curl.h>


/*
 *Will return 1 if sucessful
 *
 *
 */
int scryFall_request(char *argc)
{
	CURL *curl = curl_easy_init();
	CURlcode res;

	if(curl)
        {
                //Header init
                struct curl_slist *headers = NULL;

                headers = curl_slist_append(headers, "Accept: application/json");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

                //User Agent init
                
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "AI Project Beta (ajdefafa@gmail.com)");
                
		//Url Call
                curl_easy_setopt(curl, CURLOPT_URL, "https://api.scryfall.com/cards/named?fuzzy=zurgo%20stormrender");
                res = curl_easy_perform(curl);
                
                
		//free
		curl_easy_cleanup(curl);
                curl_slist_free_all(headers);
                
		
		

        }
        if(res != CURLE_OK) {
            fprintf(stderr, "Connection failed: %s\n", curl_easy_strerror(res));
	    return 0;
        }
	if(res == CURLE_OK)
	{
        	printf("Connection and transfer successful!\n");
        	return 0;
	}

}
