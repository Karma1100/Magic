#include <curl/curl.h>
#include <stdio.h>

int main(void)
{
	CURL *curl = curl_easy_init();
	CURLcode res;
	//FILE *fp;
	/*
	const char* filename = "testConnection.json";
	fp = fopen(filename, "wb");
	
	if(fp == NULL)
	{
		fprintf(stdout, "Did not open file");
		return 1;
	}
	*/


	

		
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
		curl_easy_cleanup(curl);
		if (headers) 
		{
           		curl_slist_free_all(headers);
        	}

	}
	if(res != CURLE_OK) {
            fprintf(stderr, "Connection failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Connection and transfer successful!\n");
        }





	return 0;
}