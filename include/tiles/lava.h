/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef LAVA_H_
#define LAVA_H_

#include "tiles/tile.h"

extern const tile_t lava;

void lava_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
bool lava_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
void lava_tick(tile_t self, floor_t *floor, sfVector2i pos);

#endif