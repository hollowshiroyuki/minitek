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

int floor_get_data(floor_t *self, sfVector2i pos)
{
    int tile_id = 0;

    if (!pos.x || !pos.y || pos.x >= self->size.x || pos.y >= self->size.y)
        return (0);
    return (self->data[pos.y * self->size.x + pos.x]);
}