/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "menu_funcs.h"
#include "recipes/recipe.h"

extern const menu_funcs_t pause_menu_funcs;

typedef struct entity_s entity_t;

typedef struct pause_menu_s
{
    int selection;
    entity_t *player;
    bool will_save;
    int timer;
} pause_menu_t;

menu_t *pause_menu_create(entity_t *player);
void pause_menu_tick(menu_t *self);
void pause_menu_draw(menu_t *self, screen_t *screen);
void pause_enu_destroy(menu_t *self);

#endif