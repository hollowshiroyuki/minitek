/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "recipes/craft.h"

void recipe_list_destroy(recipe_t *list)
{
    recipe_t *tmp;

    while (list) {
        tmp = list->next;
        (list->funcs.destroy)(list);
        list = tmp;
    }
}