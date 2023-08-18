/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "recipe_funcs.h"
#include "recipes/recipe.h"

const recipe_funcs_t recipe_funcs =
{
    .add_cost = recipe_add_cost,
    .check_can_craft = recipe_check_can_craft,
    .craft = recipe_craft,
    .deduct_cost = recipe_deduct_cost,
    .destroy = recipe_destroy
};