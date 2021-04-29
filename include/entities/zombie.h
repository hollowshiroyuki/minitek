/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "entity_funcs.h"

extern const entity_funcs_t zombie_funcs;

typedef struct mob_s mob_t;

typedef struct zombie_s
{
    mob_t *mob;
    sfVector2i off;
    int walk_time;
    int level;
} zombie_t;

#endif