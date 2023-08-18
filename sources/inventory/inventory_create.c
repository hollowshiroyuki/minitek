/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "inventory.h"

inventory_t *inventory_create(int capacity)
{
    inventory_t *new = malloc(sizeof(inventory_t));

    memset(new, 0, sizeof(inventory_t));
    new->capacity = capacity;
    new->item_count = 0;
    new->items = 0;
    return (new);
}