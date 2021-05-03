/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "menus/menu.h"
#include "menu_funcs.h"

void universe_tick(universe_t *self)
{
    input_tick(self->input);
    if (self->menu) {
        (*self->menu->funcs.tick)(self->menu);
    } else {
        floor_tick(self->active_floor);
    }
}