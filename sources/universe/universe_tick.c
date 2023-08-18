/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"

void universe_tick(universe_t *self)
{
    //if (self->menu)) {
    //    menu_tick(universe->menu);
    //} else {
        floor_tick(self->active_floor);
    //}
}