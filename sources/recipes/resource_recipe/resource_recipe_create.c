/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/furniture_recipe.h"
#include "recipes/recipe.h"
#include "recipes_id.h"

recipe_t *resource_recipe_create(resource_t *res, int count)
{
    recipe_t *new = malloc(sizeof(recipe_t));

    memset(new, 0, sizeof(recipe_t));
    new->id = R_RESOURCE;
    new->res.count = count;
    new->res.res = res;
    recipe_init(new, resource_item_create(res, count));
    recipe_funcs_combine(&new->funcs, &furniture_recipe_funcs);
    return (new);
}