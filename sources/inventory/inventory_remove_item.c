/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"
#include "resources/resource.h"

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