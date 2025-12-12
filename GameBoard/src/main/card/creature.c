#include <stdio.h>



typedef struct{
    unsigned int Flying         : 1;
	unsigned int Flash          : 1;
	unsigned int First_Strike   : 1;
	unsigned int Lifelink       : 1;
	unsigned int Hexproof       : 1;
	unsigned int Vigilance      : 1;

}KeyWords;

typedef struct{
    unsigned int ally           : 1;
    //need to add more here later    



}subclass;

typedef struct{
    int power;
    int toughness;
    unsigned int is_legendary   : 1;
    KeyWords keyword_abilities;
    
}CreatureCard;

CreatureCard* Create_CreatureCard(char* name){
    CreatureCard* newCardPtr = (CreatureCard *)malloc(sizeof(CreatureCard));

    if(newCardPtr == NULL){
        return NULL;
    }

    //API call to db to get the info to fill out fields

        
    newCardPtr->power = 1;
    newCardPtr->toughness = 1;
    newCardPtr->is_legendary = 0;
    newCardPtr->keyword_abilities = (KeyWords){0};


    return newCardPtr;
}


