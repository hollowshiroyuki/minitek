/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef CRAFTING_MENU_H_
#define CRAFTING_MENU_H_

#include "menu_funcs.h"
#include "recipes/recipe.h"

extern const menu_funcs_t crafting_menu_funcs;

typedef struct entity_s entity_t;

typedef struct crafting_menu_s
{
    int selection;
    entity_t *player;
    recipe_t *recipes;
} crafting_menu_t;

menu_t *crafting_menu_create(recipe_t *recipes, entity_t *player, char *name);
void crafting_menu_tick(menu_t *self);
void crafting_menu_draw(menu_t *self, screen_t *screen);
void crafting_menu_destroy(menu_t *self);

#endif