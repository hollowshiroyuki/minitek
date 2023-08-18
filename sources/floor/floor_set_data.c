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

void floor_set_data(floor_t *self, sfVector2i pos, int data)
{
    if (!pos.x || !pos.y || pos.x >= self->size.x || pos.y >= self->size.y)
        return;
    self->data[self->size.x * pos.y + pos.x] = data;
}