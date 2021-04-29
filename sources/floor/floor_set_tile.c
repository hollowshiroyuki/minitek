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

void floor_set_tile(floor_t *self, sfVector2i pos, const tile_t tile, int data)
{
    if (!pos.x || !pos.y || pos.x >= self->size.x || pos.y >= self->size.y)
        return;
    self->tiles[self->size.x * pos.y + pos.x] = tile.id;
    self->data[self->size.x * pos.y + pos.x] = data;
}