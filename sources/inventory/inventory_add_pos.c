/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"

static void item_list_add(item_t **list, item_t *new, int pos)
{
    item_t *tmp = *list;
    int i = 0;

    if (!tmp) {
        *list = new;
        return;
    }
    if (pos == 0) {
        new->next = tmp;
        *list = new;
        return;
    }
    while (tmp) {
        if (i == pos || !tmp->next) {
            new->next = tmp->next;
            tmp->next = new;
            return;
        }
        i++;
    }
}

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