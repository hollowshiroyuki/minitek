/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"

#include "floor.h"
#include "random.h"
#include "screen.h"
#include "tiles/dirt.h"

void farmland_step(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    if (random_int(60) != 0)
        return;
    if (floor_get_data(floor, pos) < 5)
        return;
    floor_set_tile(floor, pos, dirt, 0);
}