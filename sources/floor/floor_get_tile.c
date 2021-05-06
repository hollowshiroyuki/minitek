/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "tiles/tile.h"
#include "tiles.h"
#include "tiles_id.h"

tile_t floor_get_tile(floor_t *self, sfVector2i pos)
{
    int tile_id = 0;

    if (pos.x < 0 || pos.y < 0)
        return (*tiles[T_DIRT]);
    if (pos.x >= self->size.x || pos.y >= self->size.y)
        return (*tiles[T_DIRT]);
    tile_id = self->tiles[self->size.x * pos.y + pos.x];
    for (int i = 0; i < T_COUNT; i++) {
        if (tiles[i] && tiles[i]->id == tile_id)
            return (*tiles[i]);
    }
    return (*tiles[T_DIRT]);
}