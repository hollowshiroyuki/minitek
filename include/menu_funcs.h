/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef MENU_FUNCS_H_
#define MENU_FUNCS_H_

#include "screen.h"
#include "input.h"

typedef struct menu_s menu_t;
typedef struct universe_s universe_t;

typedef struct menu_funcs_s
{
    void (*init)(menu_t *self, universe_t *universe, input_t *input);
    void (*tick)(menu_t *self);
    void (*draw)(menu_t *self, screen_t *screen);
    void (*destroy)(menu_t *self);
} menu_funcs_t;

#endif