/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef CARROT_H_
#define CARROT_H_

#include "tiles/tile.h"

extern const tile_t carrot;

void carrot_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos);

#endif