#include <stdio.h>
#include "creature.c"




typedef enum {
    TYPE_CREATURE,
    TYPE_ENCHANTMENT,
    TYPE_SORCERY,
    TYPE_LAND,
    TYPE_INSTANT
} CardType;


typedef struct Card{
    CardType type;

    union{
        

    };




};