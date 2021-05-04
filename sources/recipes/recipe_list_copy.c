/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

static void append(recipe_t **list, recipe_t *new, item_t *item)
{
    recipe_t *tmp = *list;

    new->result = item;
    if (!tmp) {
        *list = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    tmp->result->next = new->result;
}

recipe_t *recipe_list_copy(recipe_t *list)
{
    recipe_t *r_tmp;
    item_t *i_tmp;
    recipe_t *res = 0;

    while (list) {
        r_tmp = malloc(sizeof(recipe_t));
        i_tmp = malloc(sizeof(item_t));
        *r_tmp = *list;
        *i_tmp = *list->result;
        i_tmp->next = 0;
        r_tmp->next = 0;
        append(&res, r_tmp, i_tmp);
        list = list->next;
    }
    return (res);
}