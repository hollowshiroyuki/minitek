/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "entities_id.h"
#include <stdio.h>
#include "entities/entity.h"
#include "consts.h"

void floor_remove_entity(floor_t *self, sfVector2i p, entity_t *entity)
{
    int ept = entities_per_tile;
    entity_t **list;
    int i = 0;

    if (p.x < 0 || p.y < 0 || p.x >= self->size.x || p.y >= self->size.y)
        return;
    if (entity->id == E_MOB && entity->mob.id == MB_PLAYER)
        return;
    list = self->entities_in_tiles[p.x + p.y * self->size.x];
    for (int i = 0; i < ept; i++) {
        if (list[i] == entity) {
            list[i] = 0;
            for (int j = i + 1; j < ept; j++) {
                list[j - 1] = list[j];
            }
            return;
        }
    }
}