/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "floor.h"

void floor_destroy(floor_t *self)
{
    if (!self)
        return;
    if (self->data)
        free(self->data);
    if (self->tiles)
        free(self->tiles);
    //if (self->entities)
    //    entities_destroy(self->entities);
    free(self);
}