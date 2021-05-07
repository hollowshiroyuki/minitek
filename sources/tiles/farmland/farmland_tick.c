/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "index_til.h"
#include "floor.h"
#include "random.h"
#include "screen.h"
#include <stdio.h>

void farmland_tick(tile_t *self, floor_t *floor, sfVector2i pos)
{
    printf("Reading %i, %i\n", pos.x, pos.y);
    int age = floor_get_data(floor, pos);

    if (age < 5)
        floor_set_data(floor, pos, age + 1);
}