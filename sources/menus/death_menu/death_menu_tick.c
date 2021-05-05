/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"
#include "resources/item.h"

static void input(menu_t *self, int len)
{
    if (self->input->up.clicked)
        self->dea.selection--;
    if (self->input->down.clicked)
        self->dea.selection++;
    self->dea.selection = (len == 0) ? 0 : self->dea.selection;
    self->dea.selection += (self->dea.selection < 0) ? len : 0;
    self->dea.selection -= (self->dea.selection >= len) ? len : 0;
}

void revive(menu_t *self)
{
    return;
}

void death_menu_tick(menu_t *self)
{
    input(self, 3);
    if (self->input->attack.clicked || self->input->accept.clicked) {
        if (self->dea.selection == 0)
            revive(self);
        if (self->dea.selection == 1)
            return;
        if (self->dea.selection == 2)
            return;
    }
}