/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TITLE_MENU_H_
#define TITLE_MENU_H_

#include "menu_funcs.h"

extern const menu_funcs_t title_menu_funcs;

typedef struct title_menu_s
{
    int selection;
} title_menu_t;

void title_menu_tick(menu_t *self);
void title_menu_draw(menu_t *self, screen_t *screen);

#endif