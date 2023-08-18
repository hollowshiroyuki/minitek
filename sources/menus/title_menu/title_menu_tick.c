/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"

static void input(menu_t *self)
{
    if (self->input->up.clicked)
        self->title.selection--;
    if (self->input->down.clicked)
        self->title.selection++;
    if (self->title.selection < 0)
        self->title.selection += 4;
    if (self->title.selection >= 4)
        self->title.selection -= 4;
}

void title_menu_tick(menu_t *self)
{
    input(self);
    if (self->input->accept.clicked) {
        if (self->title.selection == 0) {
            universe_set_menu(self->universe, NULL);
            (self->funcs.destroy)(self);
        }
    }
}