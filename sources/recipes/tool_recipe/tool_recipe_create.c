/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/tool_recipe.h"
#include "recipes/recipe.h"
#include "recipes_id.h"

recipe_t *tool_recipe_create(tool_type_t *type, int level)
{
    recipe_t *new = malloc(sizeof(recipe_t));

    memset(new, 0, sizeof(recipe_t));
    new->id = R_TOOL;
    new->tool.type = type;
    new->tool.level = level;
    recipe_init(new, tool_item_create(type, level));
    recipe_funcs_combine(&new->funcs, &tool_recipe_funcs);
    return (new);
}