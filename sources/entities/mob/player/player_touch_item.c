/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"

void player_touch_item(entity_t *self, entity_t *item)
{
    item_entity_take(item, self);
    inventory_add(self->mob.pla.inventory, item->itm.item);
}