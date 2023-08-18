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
#include "universe.h"

extern const menu_funcs_t world_select_menu_funcs;

typedef struct world_entry_s
{
    char name[20];
    bool error;
} world_entry_t;

typedef struct world_select_menu_s
{
    int selection;
    bool error;
    menu_t *parent;
    world_entry_t *worlds[21];
    char name[20];
    char seed[8];
    int stage;
    universe_t *universe;
} world_select_menu_t;

menu_t *world_select_menu_create(input_t *input, menu_t *parent);
void world_select_menu_destroy(menu_t *self);
void world_select_menu_tick(menu_t *self);
void world_select_menu_draw(menu_t *self, screen_t *screen);

#endif