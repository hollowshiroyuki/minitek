/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef DIRT_H_
#define DIRT_H_

#include "tiles/tile.h"

extern const tile_t dirt;

void dirt_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
bool dirt_interact(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);

#endif