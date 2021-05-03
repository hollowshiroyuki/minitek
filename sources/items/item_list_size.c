/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

int item_list_size(item_t *list)
{
    int i = 0;

    while (list) {
        list = list->next;
        i++;
    };
    return (i);
}