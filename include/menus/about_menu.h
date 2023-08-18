/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ABOUT_MENU_H_
#define ABOUT_MENU_H_

#include "menu_funcs.h"
#include <stdbool.h>

extern const menu_funcs_t about_menu_funcs;

typedef struct about_menu_s
{
    int page;
    menu_t *parent;
} about_menu_t;

menu_t *about_menu_create(input_t *input, menu_t *ptr);
void about_menu_tick(menu_t *self);
void about_menu_draw(menu_t *self, screen_t *screen);

#endif