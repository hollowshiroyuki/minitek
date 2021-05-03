/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

void item_list_add(item_t **list, item_t *new, int pos)
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