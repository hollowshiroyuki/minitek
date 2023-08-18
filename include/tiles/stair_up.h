/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef STAIRUP_H_
#define STAIRUP_H_

#include "tiles/tile.h"

extern const tile_t stair_up;

void stair_up_render(tile_t self, screen_t *scr, floor_t *flr, sfVector2i p);

#endif