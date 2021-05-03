/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void recipe_init(recipe_t *self, item_t *item)
{
    self->result = item;
}