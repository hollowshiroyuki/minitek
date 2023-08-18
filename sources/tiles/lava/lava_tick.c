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
#include "tiles/lava.h"
#include <stdio.h>

void lava_tick(tile_t self, floor_t *floor, sfVector2i pos)
{
    sfVector2i npos = pos;

    if (random_int(1)) {
        npos.x += random_int(2) * 2 - 1;
    } else {
        npos.y += random_int(2) * 2 - 1;
    }
    if (floor_get_tile(floor, npos).id == T_HOLE)
        floor_set_tile(floor, npos, lava, 0);
}