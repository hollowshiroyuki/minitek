/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"
#include "resources/resource.h"

static void item_list_remove(item_t **list, item_t *item)
{
    item_t *tmp = *list;
    item_t *prv = NULL;

    if (tmp == item) {
        *list = tmp->next;
        (*tmp->funcs.destroy)(tmp);
        return;
    } else {
        while (tmp && tmp != item) {
            prv = tmp;
            tmp = tmp->next;
        }
        if (tmp) {
            prv->next = tmp->next;
            (*tmp->funcs.destroy)(tmp);
        }
    }
}

bool inventory_remove_resource(inventory_t *self, resource_t *res, int count)
{
    item_t *has = inventory_find_resource(self, res);

    if (!has)
        return (false);
    if (has->res.count < count)
        return (false);
    has->res.count -= count;
    if (has->res.count <= 0) {
        item_list_remove(&self->items, has);
        self->item_count--;
    }
    return (true);
}