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
    } else {
        while (tmp && tmp != item) {
            prv = tmp;
            tmp = tmp->next;
        }
        if (tmp) {
            prv->next = tmp->next;
        }
    }
}

item_t *inventory_remove_item(inventory_t *self, int pos)
{
    item_t *to_remove = self->items;

    if (pos > self->item_count)
        return (0);
    for (int i = 0; i < pos; i++)
        to_remove = to_remove->next;
    item_list_remove(&self->items, to_remove);
    return (to_remove);
}