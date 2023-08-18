/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ORE_H_
#define ORE_H_

#include "tiles/tile.h"

extern const tile_t iron_ore;
extern const tile_t lapis_ore;
extern const tile_t gold_ore;
extern const tile_t gem_ore;

void ore_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
bool ore_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);

#endif