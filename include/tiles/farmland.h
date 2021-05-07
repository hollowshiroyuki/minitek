/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FARMLAND_H_
#define FARMLAND_H_

#include "tiles/tile.h"

extern const tile_t farmland;

void farmland_tick(tile_t self, floor_t *floor, sfVector2i pos);
void farmland_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p);
void farmland_step(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);

#endif