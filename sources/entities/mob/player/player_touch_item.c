/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "items_id.h"
#include "entities/entity.h"

void player_touch_item(entity_t *self, entity_t *item)
{
    inventory_t *inv = self->mob.pla.inventory;
    bool full = item_list_size(inv->items) >= inv->capacity;
    item_t *has;

    if (full && item->itm.item->id != I_RESOURCE)
        return;
    has = inventory_find_resource(inv, item->itm.item->res.resource);
    if (full && !has)
        return;
    item_entity_take(item, self);
    inventory_add(self->mob.pla.inventory, item->itm.item);
}