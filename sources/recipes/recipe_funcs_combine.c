/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "recipe_funcs.h"
#include "recipes/recipe.h"

void recipe_funcs_combine(recipe_funcs_t *d, const recipe_funcs_t *r_f)
{
    d->add_cost = r_f->add_cost ?: recipe_funcs.add_cost;
    d->check_can_craft = r_f->check_can_craft ?: recipe_funcs.check_can_craft;
    d->craft = r_f->check_can_craft ?: recipe_funcs.check_can_craft;
    d->deduct_cost = r_f->deduct_cost ?: recipe_funcs.deduct_cost;
    d->destroy = r_f->destroy ?: recipe_funcs.destroy;
}