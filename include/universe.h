/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include "floor.h"
//#include "input.h"
#include "entities/entity.h"

typedef struct universe_s
{
    bool running;
    floor_t *active_floor;
    input_t *input;
    floor_t *floors[16];
    long tick_count;
    entity_t *player;
    //menu_t *menu;
} universe_t;

void universe_tick(universe_t *self);
universe_t *universe_create(sfVector2i size, input_t *input);
void universe_draw(universe_t *self, screen_t *screen);
void universe_destroy(universe_t *self);

#endif