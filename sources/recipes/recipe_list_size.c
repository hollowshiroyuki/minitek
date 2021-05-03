/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

int recipe_list_size(recipe_t *list)
{
    int i = 0;

    while (list) {
        list = list->next;
        i++;
    }
    return (i);
}