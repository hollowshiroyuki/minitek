/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"

void item_entity_touched_by(entity_t *self, entity_t *entity)
{
    if (self->itm.time > 30 && !self->removed)
        (*entity->funcs.touch_item)(entity, self);
}