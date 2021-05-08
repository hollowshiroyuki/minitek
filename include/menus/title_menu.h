/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TITLE_MENU_H_
#define TITLE_MENU_H_

#include "menu_funcs.h"
#include "rpg.h"

extern const menu_funcs_t title_menu_funcs;

typedef struct title_menu_s
{
    int selection;
    sfSprite *background;
    sfTexture *texture;
    menu_data_t *data;
} title_menu_t;

menu_t *title_menu_create(menu_data_t *data);
void title_menu_tick(menu_t *self);
void title_menu_draw(menu_t *self, screen_t *screen);
void title_menu_destroy(menu_t *self);

#endif