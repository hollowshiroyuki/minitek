/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"
#include "resources/resource.h"

int inventory_count(inventory_t *self, item_t *item)
{
    item_t *tmp;
    int count = 0;

    if (item->id == I_RESOURCE) {
        tmp = inventory_find_resource(self, item->res.resource);
        if (tmp)
            return (tmp->res.count);
    } else {
        for (item_t *cur = self->items; cur; cur = cur->next) {
            if ((item->funcs.matches)(item, cur)) {
                count++;
            }
        }
        return (count);
    }
    return (0);
}