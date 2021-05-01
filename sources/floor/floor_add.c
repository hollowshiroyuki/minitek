/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "entities_id.h"
#include "entities/entity.h"
#include <stdio.h>

void floor_add(floor_t *self, entity_t *entity)
{
    sfVector2i e_pos = (sfVector2i){entity->pos.x >> 4, entity->pos.y >> 4};

    if (entity->id == E_PLAYER)
        self->player = entity;
    entity->removed = false;
    entities_add(&self->entities, entity);
    (entity->funcs.init)(entity, self);
    floor_insert_entity(self, e_pos, entity);
}