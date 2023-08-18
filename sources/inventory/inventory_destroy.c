/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "inventory.h"

void inventory_destroy(inventory_t *self)
{
    item_t *tmp = self->items;
    item_t *next = 0;

    while (tmp) {
        next = tmp->next;
        (*tmp->funcs.destroy)(tmp);
        tmp = next;
    }
    free(self);
}