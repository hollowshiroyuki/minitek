/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef SLIME_H_
#define SLIME_H_

#include "entity_funcs.h"

typedef struct mob_s mob_t;
typedef struct entity_s entity_t;

extern const entity_funcs_t slime_funcs;

typedef struct slime_s
{
    sfVector2i off;
    int jump_time;
    int level;
    mob_t *mob;
} slime_t;

entity_t *slime_create(void);

#endif