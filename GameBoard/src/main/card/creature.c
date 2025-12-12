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
    int power;
    int toughness;
    KeyWords keyword_abilities;
    
}CreatureCard;


