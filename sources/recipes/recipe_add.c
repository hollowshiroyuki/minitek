/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void recipe_add(recipe_t **list, recipe_t *recipe)
{
    recipe->next = *list;
    *list = recipe;
}