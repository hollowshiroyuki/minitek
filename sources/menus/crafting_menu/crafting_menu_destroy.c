/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"
#include "recipes/recipe.h"

void crafting_menu_destroy(menu_t *self)
{
    recipe_list_delink(self->craft.recipes);
    menu_destroy(self);
}