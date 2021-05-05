/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "menus/menu.h"
#include "menus/floor_change_menu.h"

void universe_tick(universe_t *self)
{
    int dir = self->floor_change;

    self->tick_count++;
    if (input_tick(self->input))
        return;
    if (self->menu) {
        (*self->menu->funcs.tick)(self->menu);
    } else {
        if (self->player->removed) {
            universe_set_menu(self, death_menu_create(self->player));
            return;
        }
        if (self->floor_change) {
            universe_set_menu(self, floor_change_menu_create(dir));
            self->floor_change = 0;
            return;
        }
        floor_tick(self->active_floor);
    }
}