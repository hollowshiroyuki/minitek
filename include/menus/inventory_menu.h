/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef INVENTORY_MENU_H_
#define INVENTORY_MENU_H_

#include "menu_funcs.h"

extern const menu_funcs_t inventory_menu_funcs;

typedef struct entity_s entity_t;

typedef struct inventory_menu_s
{
    int selection;
    entity_t *player;
} inventory_menu_t;

menu_t *inventory_menu_create(entity_t *player, char *name);
void inventory_menu_tick(menu_t *self);
void inventory_menu_draw(menu_t *self, screen_t *screen);

#endif