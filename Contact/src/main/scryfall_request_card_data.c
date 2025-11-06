#include "scryfall_request_card_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>







typedef struct{
	char *data;
	size_t size;

}memory_buffer;



#define WAIT_TIME 200000

/*
 *Need to be appended to the end of the api url. Spaces do not need to be accounted for as http will deal with it
 */
char *formatting_url(char *url, char *card)
{
	printf("Card Name: %s\n",card);
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



/*
 *Need to write a function to handel the callback for the memory_buffer
 *
 * */


static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) 
{
    	
	size_t total_size = size * nmemb;
	memory_buffer *mem = (memory_buffer *)userp;

	// 1. Reallocate: Try to resize the buffer to fit the new data
	char *ptr = realloc(mem->data, mem->size + total_size + 1); // +1 for null terminator

	if (ptr == NULL) 
	{
		// Handle memory reallocation failure (out of memory)
		fprintf(stderr, "Out of memory in write_callback!\n");
		return 0; // Return 0 to signal an error to curl
	}

	mem->data = ptr;

	// 2. Append: Copy the new chunk of data to the end of the existing buffer
	memcpy(&(mem->data[mem->size]), contents, total_size);

	// 3. Update: Increase the tracked size and add the null terminator
	mem->size += total_size;
	mem->data[mem->size] = '\0';

	return total_size; // Return the number of bytes processed
}




int scryfall_request_card_data(char *card_name)
{
	CURL *curl = curl_easy_init();
	CURLcode res;

	char *base_url = "https://api.scryfall.com/cards/named?fuzzy=";
	
	char *request_url = formatting_url(base_url, card_name);
	
	
	memory_buffer chunk;
	chunk.data = (char*)malloc(1); // Start with a 1-byte buffer
	chunk.size = 0;	 



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

		//setting write function
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

                
		//hard coding in request per second to 5
		usleep(WAIT_TIME);
		
		
		res = curl_easy_perform(curl);

			
		printf("Chunk print: %s\n", chunk.data);
        //free
		curl_easy_cleanup(curl);
		curl_slist_free_all(headers);
		free(chunk.data);
    }

	if(request_url != NULL)
	{
		printf("request link: %s\n", request_url);
		free(request_url);
	}

	if(res != CURLE_OK) {
		fprintf(stderr, "Connection failed: %s\n", curl_easy_strerror(res));
		return -1;
	}
	if(res == CURLE_OK)
	{
			printf("Connection and transfer successful!\n");
			return 0;
	}

	
}


