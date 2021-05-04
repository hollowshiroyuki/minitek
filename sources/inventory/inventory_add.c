/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"

void inventory_add(inventory_t *self, item_t *item)
{
    inventory_add_pos(self, item, item_list_size(self->items));
}