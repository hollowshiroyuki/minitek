/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef STAIRDOWN_H_
#define STAIRDOWN_H_

#include "tiles/tile.h"

extern const tile_t stair_down;

void stair_down_render(tile_t self, screen_t *scr, floor_t *fl, sfVector2i p);

#endif