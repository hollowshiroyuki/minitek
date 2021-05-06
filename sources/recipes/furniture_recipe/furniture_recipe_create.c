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

recipe_t *furniture_recipe_create(entity_t *(*func)(void))
{
    recipe_t *new = malloc(sizeof(recipe_t));
    entity_t *furniture = (*func)();

    memset(new, 0, sizeof(recipe_t));
    new->id = R_FURNITURE;
    new->fur.create_furniture = func;
    recipe_init(new, furniture_item_create(furniture));
    recipe_funcs_combine(&new->funcs, &furniture_recipe_funcs);
    return (new);
}