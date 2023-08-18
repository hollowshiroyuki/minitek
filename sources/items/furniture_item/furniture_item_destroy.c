/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include "resources/item.h"
#include "entities/entity.h"

void furniture_item_destroy(item_t *self)
{
    if (!(self->funcs.is_depleted)(self)) {
        (self->fur.furniture->funcs.destroy)(self->fur.furniture);
    }
    item_destroy(self);
}