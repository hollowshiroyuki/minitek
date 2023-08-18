/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "resources/item.h"

void item_list_add(item_t **list, item_t *new, int pos)
{
    item_t *tmp;

    if (pos < 1 || pos > item_list_size(*list) + 1)
        pos = item_list_size(*list) + 1;
    while (pos--) {
        if (pos == 0) {
            new->next = *list;
            *list = new;
        } else {
            list = &(*list)->next;
        }
    }
}