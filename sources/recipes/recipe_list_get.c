/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

recipe_t *recipe_list_get(recipe_t *recipe, int pos)
{
    int i = 0;

    while (recipe) {
        if (i == pos) {
            return (recipe);
        }
        i++;
        recipe = recipe->next;
    }
    return (0);
}