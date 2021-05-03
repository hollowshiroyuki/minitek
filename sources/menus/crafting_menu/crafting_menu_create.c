/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus_id.h"
#include "universe.h"
#include "hsy.h"
#include <stdio.h>

menu_t *crafting_menu_create(recipe_t *recipes, entity_t *player, char *title)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_CRAFTING;
    new->craft.player = player;
    new->craft.recipes = recipe_list_copy(recipes);
    new->name = hsy_strdup(title);
    for (recipe_t *cur = new->craft.recipes; cur; cur = cur->next)
        (*cur->funcs.check_can_craft)(cur, player);
    recipe_list_sort(&new->craft.recipes);
    new->funcs = crafting_menu_funcs;
    return (new);
}