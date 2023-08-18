/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef UNIVERSE_SELECTION_MENU_H_
#define UNIVERSE_SELECTION_MENU_H_

#include "menu_funcs.h"
#include "rpg.h"

extern const menu_funcs_t universe_selection_menu_funcs;

typedef struct universe_selection_menu_s
{
    int selection;
} universe_selection_menu_t;

menu_t *universe_selection_menu_create(menu_t *parent);
void universe_selection_menu_tick(menu_t *self);
void universe_selection_menu_draw(menu_t *self, screen_t *screen);

#endif