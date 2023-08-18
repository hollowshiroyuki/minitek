/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TILE_H_
#define TILE_H_

#include <stdbool.h>
#include "screen.h"

typedef struct floor_s floor_t;
typedef struct entity_s entity_t;

typedef struct tile_s tile_t;

typedef struct tile_s
{
    int id;
    bool water;
    bool sand;
    bool grass;
    bool lava;
    void (*render)(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
    void (*bump)(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
    bool (*may_pass)(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
    void (*step)(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
    bool (*interact)(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
    bool (*use)(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
    void (*tick)(tile_t self, floor_t *floor, sfVector2i pos);
    void (*hurt)(floor_t *floor, sfVector2i pos, entity_t *entity, int dmg);
} tile_t;

#endif