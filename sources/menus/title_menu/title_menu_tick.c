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

static void menu_actions(menu_t *self)
{
    if (self->input->accept.clicked) {
        if (self->title.selection == 0) {
            self->child = world_select_menu_create(self->input, self);
        }
        if (self->title.selection == 1) {
            self->child = options_menu_create(self->input, self);
        }
        if (self->title.selection == 3) {
            self->title.data->stop = true;
        }
    }
}

void title_menu_tick(menu_t *self)
{
    input_t *in = self->title.data->input;

    if (self->child) {
        (*self->child->funcs.tick)(self->child);
        return;
    }
    input(self);
    menu_actions(self);
}