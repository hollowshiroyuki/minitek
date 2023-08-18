/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef WATER_H_
#define WATER_H_

#include "tiles/tile.h"

extern const tile_t water;

void water_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
bool water_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);

#endif