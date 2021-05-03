/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef CACTUS_H_
#define CACTUS_H_

#include "tiles/tile.h"

extern const tile_t cactus;
bool cactus_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
void cactus_bump(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
void cactus_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);

#endif