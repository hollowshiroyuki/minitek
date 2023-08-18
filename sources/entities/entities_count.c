/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

int entities_count(entity_t *list)
{
    int i = 0;

    if (!list)
        return (0);
    while (list) {
        i++;
        list = list->next;
    }
    return (i);
}