/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"
#include "recipes/recipe.h"
#include "resources/resources.h"
#include "resources/tool_item.h"

recipe_t *workbench_recipes_create(void)
{
    recipe_t *recipes = 0;

    recipe_add(&recipes, tool_recipe_create((tool_type_t *)&sword_type, 0));
    recipe_add_cost(recipes, (resource_t *)&r_wood, 1);
    recipe_add(&recipes, tool_recipe_create((tool_type_t *)&sword_type, 1));
    recipe_add_cost(recipes, (resource_t *)&r_bread, 2);
    return (recipes);
}