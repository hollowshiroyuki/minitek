/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity_funcs.h"
#include "input.h"
#include "screen.h"
#include "floor.h"

typedef struct mob_s mob_t;
typedef struct entity_s entity_t;
typedef struct universe_s universe_t;

extern const entity_funcs_t player_funcs;

typedef struct player_s
{
    int invul;
    int stamina_delay;
    int stamina_reload;
    int max_stamina;
    int stamina;
    universe_t *universe;
    input_t *input;
    //inventory_t *inventory;
    //item_t *active_item;
    mob_t *mob;
} player_t;

void player_tick(entity_t *self);
entity_t *player_create(universe_t *universe, input_t *input);
void player_draw(entity_t *self, screen_t *screen);
void player_find_start_pos(entity_t *self, floor_t *floor);


#endif