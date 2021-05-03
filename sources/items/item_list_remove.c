/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

void item_list_remove(item_t **list, item_t *item)
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