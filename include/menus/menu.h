/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef MENU_H_
#define MENU_H_

#include "input.h"
#include "menu_funcs.h"
#include "menus/title_menu.h"
#include "menus/inventory_menu.h"
#include "menus/crafting_menu.h"
#include "menus/floor_change_menu.h"
#include "menus/death_menu.h"
#include "resources/item.h"

typedef struct universe_s universe_t;

extern const menu_funcs_t menu_funcs;

typedef struct menu_s
{
    int id;
    universe_t *universe;
    input_t *input;
    char *name;
    union {
        title_menu_t title;
        inventory_menu_t inv;
        crafting_menu_t craft;
        death_menu_t dea;
        floor_change_menu_t flc;
    };
    menu_funcs_t funcs;
} menu_t;

void menu_init(menu_t *self, universe_t *universe, input_t *input);
void menu_tick(menu_t *self);
void menu_draw(menu_t *self, screen_t *screen);
void menu_destroy(menu_t *self);
void menu_draw_item_list(menu_t *self, screen_t *scr, int v[5], item_t *list);

#endif