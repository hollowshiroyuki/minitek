/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ROCK_H_
#define ROCK_H_

#include "tiles/tile.h"

extern const tile_t rock;

void rock_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);
bool rock_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);
void rock_damage(floor_t *floor, sfVector2i pos, int dmg);
void rock_hurt(floor_t *floor, sfVector2i pos, entity_t *entity, int dmg);
bool rock_interact(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e);

#endif