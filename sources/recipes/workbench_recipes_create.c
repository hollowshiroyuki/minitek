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
#include "entities/workbench.h"

static void stone_tools_recipes(recipe_t **recipes)
{
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&sword_type, 1));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add_cost(*recipes, (resource_t *)&r_stone, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&axe_type, 1));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add_cost(*recipes, (resource_t *)&r_stone, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&hoe_type, 1));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add_cost(*recipes, (resource_t *)&r_stone, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&pick_type, 1));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add_cost(*recipes, (resource_t *)&r_stone, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&shovel_type, 1));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add_cost(*recipes, (resource_t *)&r_stone, 5);
}

static void tools_recipes(recipe_t **recipes)
{
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&sword_type, 0));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&axe_type, 0));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&hoe_type, 0));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&pick_type, 0));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    recipe_add(recipes, tool_recipe_create((tool_type_t *)&shovel_type, 0));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 5);
    stone_tools_recipes(recipes);
}

static void furniture_recipes(recipe_t **recipes)
{
    recipe_add(recipes, furniture_recipe_create(workbench_create));
    recipe_add_cost(*recipes, (resource_t *)&r_wood, 20);
}

recipe_t *workbench_recipes_create(void)
{
    recipe_t *recipes = 0;

    tools_recipes(&recipes);
    furniture_recipes(&recipes);
    return (recipes);
}