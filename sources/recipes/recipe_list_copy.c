/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

static void append(recipe_t **list, recipe_t *new)
{
    recipe_t *tmp = *list;

    if (!tmp) {
        *list = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

recipe_t *recipe_list_copy(recipe_t *list)
{
    recipe_t *tmp;
    recipe_t *res = 0;

    while (list) {
        tmp = malloc(sizeof(recipe_t));
        *tmp = *list;
        tmp->next = 0;
        append(&res, tmp);
        list = list->next;
    }
    return (res);
}