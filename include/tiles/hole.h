/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef HOLE_H_
#define HOLE_H_

#include "tiles/tile.h"

extern const tile_t hole;

void hole_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);

#endif