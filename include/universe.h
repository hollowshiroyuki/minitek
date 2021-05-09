/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include "floor.h"
#include "input.h"
#include "menus/menu.h"
#include "screen.h"
#include "entities/entity.h"
#include "recipes/craft.h"
#include "limits.h"

typedef struct universe_s
{
    char path[PATH_MAX];
    char *name;
    bool running;
    bool to_main_menu;
    int floor_change;
    int seeds[2];
    floor_t *active_floor;
    input_t *input;
    floor_t *floors[16];
    craft_t *craft;
    long tick_count;
    entity_t *player;
    menu_t *menu;
    screen_t *screen;
} universe_t;

void universe_tick(universe_t *self);
universe_t *universe_create(sfVector2i size, input_t *input, int sd, char *p);
void universe_draw(universe_t *self, screen_t *screen);
void universe_destroy(universe_t *self);
void universe_draw_gui(universe_t *self, screen_t *screen);
void universe_set_menu(universe_t *self, menu_t *menu);
void universe_change_floor(universe_t *self, int dir);
bool universe_save(universe_t *self);
universe_t *universe_load_from_file(char *name);
void universe_kickstart(universe_t *self, input_t *input);

#endif