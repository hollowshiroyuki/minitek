/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef DEATH_MENU_H_
#define DEATH_MENU_H_

#include "menu_funcs.h"
#include "recipes/recipe.h"

extern const menu_funcs_t death_menu_funcs;

typedef struct entity_s entity_t;

typedef struct death_menu_s
{
    int selection;
    entity_t *player;
} death_menu_t;

menu_t *death_menu_create(entity_t *player);
void death_menu_tick(menu_t *self);
void death_menu_draw(menu_t *self, screen_t *screen);
void death_menu_destroy(menu_t *self);

#endif