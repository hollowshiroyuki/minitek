/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"

void inventory_add_pos(inventory_t *self, item_t *item, int pos)
{
    item_t *has = 0;

    if (item->id == I_RESOURCE) {
        has = inventory_find_resource(self, item->res.resource);
        if (!has) {
            item_list_add(&self->items, item, self->item_count);
            self->item_count++;
        } else {
            has->res.count += item->res.count;
            (item->funcs.destroy)(item);
        }
    } else {
        item_list_add(&self->items, item, self->item_count);
        self->item_count++;
    }
}