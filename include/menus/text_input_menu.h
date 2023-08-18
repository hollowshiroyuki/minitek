/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TEXT_INPUT_MENU_H_
#define TEXT_INPUT_MENU_H_

#include "menu_funcs.h"
#include <stdbool.h>

extern const menu_funcs_t text_input_menu_funcs;

typedef struct text_input_menu_s
{
    menu_t *parent;
    char *buf;
    int buf_len;
} text_input_menu_t;

menu_t *text_input_menu_create(char *dest, int len, char *name, menu_t *parent);
void text_input_menu_tick(menu_t *self);
void text_input_menu_draw(menu_t *self, screen_t *screen);
void text_input_menu_destroy(menu_t *self);

#endif