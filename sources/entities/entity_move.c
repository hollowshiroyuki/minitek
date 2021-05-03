/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

bool entity_move(entity_t *self, sfVector2i pos)
{
    sfVector2i tile_pos = {self->pos.x >> 4, self->pos.y >> 4};
    tile_t tile;
    bool stop = true;

    if (pos.x || pos.y) {
        if (pos.x && entity_move_axis(self, (sfVector2i){pos.x, 0}))
            stop = false;
        if (pos.y && entity_move_axis(self, (sfVector2i){0, pos.y}))
            stop = false;
        if (!stop) {
            tile = floor_get_tile(self->floor, tile_pos);
            if (tile.step)
                (*tile.step)(tile, self->floor, tile_pos, self);
        }
        return (!stop);
    }
    return (true);
}