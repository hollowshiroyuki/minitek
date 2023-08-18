/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "floor.h"
#include "entities/entity.h"

void floor_destroy(floor_t *self)
{
    if (!self)
        return;
    if (self->data)
        free(self->data);
    if (self->tiles)
        free(self->tiles);
    if (self->entities)
        while (self->entities)
            entities_remove(&self->entities, self->entities);
    for (int i = 0; i < self->size.x * self->size.y; i++)
        free(self->entities_in_tiles[i]);
    free(self->entities_in_tiles);
    free(self->entities_row);
    free(self);
}