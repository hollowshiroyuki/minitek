/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include "entities/entity.h"

void item_entity_destroy(entity_t *self)
{
    if (self->itm.item && !self->itm.picked_up) {
        (*self->itm.item->funcs.destroy)(self->itm.item);
    }
    entity_destroy(self);
}