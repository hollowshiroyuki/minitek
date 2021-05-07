/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "floor.h"
#include "entities_id.h"
#include "entities/entity.h"
#include "consts.h"

void floor_insert_entity(floor_t *self, sfVector2i pos, entity_t *entity)
{
    if (pos.x < 0 || pos.y < 0)
        return;
    if (pos.x >= self->size.x || pos.y >= self->size.y)
        return;
    for (int i = 0; i < entities_per_tile; i++) {
        if (!self->entities_in_tiles[pos.y * self->size.x + pos.x][i]) {
            self->entities_in_tiles[pos.y * self->size.x + pos.x][i] = entity;
            return;
        }
    }
}