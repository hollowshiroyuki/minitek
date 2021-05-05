/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"

void item_entity_take(entity_t *self, entity_t *player)
{
    (self->itm.item->funcs.on_take)(self->itm.item, self);
    self->itm.picked_up = true;
    self->removed = true;
}