/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "screen.h"
#include "floor.h"
#include <stdio.h>

void universe_draw_gui(universe_t *self, screen_t *screen)
{
    if (self->menu)
        (*self->menu->funcs.draw)(self->menu, screen);
}