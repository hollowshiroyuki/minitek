/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FLOOR_CHANGE_MENU_H_
#define FLOOR_CHANGE_MENU_H_

#include "menu_funcs.h"

extern const menu_funcs_t floor_change_menu_funcs;

typedef struct entity_s entity_t;

typedef struct floor_change_menu_s
{
    int time;
    int dir;
} floor_change_menu_t;

menu_t *floor_change_menu_create(int dir);
void floor_change_menu_tick(menu_t *self);
void floor_change_menu_draw(menu_t *self, screen_t *screen);

#endif