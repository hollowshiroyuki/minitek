/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef OPTIONS_MENU_H_
#define OPTIONS_MENU_H_

#include "menu_funcs.h"
#include <stdbool.h>

extern const menu_funcs_t options_menu_funcs;
extern const char *keys_strings[];
extern const char *controls_strings[];

typedef struct options_menu_s
{
    menu_t *parent;
    int selection;
    bool save_next;
} options_menu_t;

menu_t *options_menu_create(input_t *input, menu_t *ptr);
void options_menu_tick(menu_t *self);
void options_menu_draw(menu_t *self, screen_t *screen);

#endif