#include <stdio.h>

typedef struct {
	unsigned int flash 		: 1;
	unsigned int lifelink 	: 1;
	unsigned int deathtouch : 1;

}keywords;

typedef struct{
	int power;
	int toughness;
	keywords keys;

}Card;

int main(){
	Card cardA = {
		.power = 2,
		.toughness = 1,
		.keys = {0}
	};

	//Another way of setting to 0 
	cardA.keys = (keywords){0};

	cardA.keys.flash = 1;

	if(cardA.keys.flash == 1){
		printf("This card has flash\n");

	}
	else{
		printf("this card doesnt have flash\n");
	}
	if(cardA.keys.deathtouch == 1){
		printf("This card has deathtouch\n");

	}
	else{
		printf("value %d\n", cardA.keys.deathtouch);
	}

		free(cardA);
}
