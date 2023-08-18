/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/recipe.h"
#include "resources/item.h"

void recipe_add_cost(recipe_t *self, resource_t *res, int count)
{
    item_t *cost = resource_item_create(res, count);

    item_list_add(&self->cost, cost, item_list_size(self->cost));
}