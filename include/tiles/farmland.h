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

void farmland_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p);

#endif