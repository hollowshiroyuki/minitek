/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void recipe_add(recipe_t **old, recipe_t *new)
{
    new->next = *old;
    new->result->next = (*old) ? (*old)->result : 0;
    *old = new;
}