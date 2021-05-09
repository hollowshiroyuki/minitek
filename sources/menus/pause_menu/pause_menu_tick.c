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

static void save(menu_t *self)
{
    if (self->pause.timer < 10) {
        self->pause.timer++;
        return;
    }
    universe_save(self->pause.player->mob.pla.universe);
    input_release_all(self->input);
    self->pause.will_save = false;
    self->pause.timer = 0;
}

static void to_main_menu(menu_t *self)
{
    self->pause.player->mob.pla.universe->running = false;
    self->pause.player->mob.pla.universe->to_main_menu = true;
}

static void quit(menu_t *self)
{
    self->pause.player->mob.pla.universe->running = false;
    self->pause.player->mob.pla.universe->to_main_menu = false;
}

void pause_menu_tick(menu_t *self)
{
    input(self, 4);
    if (self->pause.will_save)
        save(self);
    if (self->input->escape.clicked) {
        universe_set_menu(self->pause.player->mob.pla.universe, NULL);
        (*self->funcs.destroy)(self);
        return;
    }
    if (self->input->attack.clicked || self->input->accept.clicked) {
        if (self->dea.selection == 0) {
            universe_set_menu(self->pause.player->mob.pla.universe, NULL);
            (*self->funcs.destroy)(self);
        }
        if (self->dea.selection == 1)
            self->pause.will_save = true;
        if (self->dea.selection == 2)
            to_main_menu(self);
        if (self->pause.selection == 3)
            quit(self);
    }
}