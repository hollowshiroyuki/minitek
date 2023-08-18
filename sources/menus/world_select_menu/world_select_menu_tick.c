/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"
#include "hsy.h"
#include  "random.h"

static void input(menu_t *self)
{
    int arr_len = 0;

    for (int i = 0; self->wsm.worlds[i]; i++)
        arr_len++;
    if (self->input->up.clicked)
        self->title.selection--;
    if (self->input->down.clicked)
        self->title.selection++;
    if (self->title.selection < 0)
        self->title.selection += arr_len;
    if (self->title.selection >= arr_len)
        self->title.selection -= arr_len;
}

void load_file(menu_t *self)
{
    char *select = self->wsm.worlds[self->wsm.selection]->name;

    self->wsm.universe = 0;
    if (self->wsm.universe) {
        self->wsm.parent->title.data->universe = self->wsm.universe;
    } else {
        self->wsm.worlds[self->wsm.selection]->error = true;
    }
}

bool creation_steps_next(menu_t *self)
{
    int sd = hsy_atoi(self->wsm.seed);
    char *name = self->wsm.name;
    sfVector2i size = (sfVector2i){256, 256};

    if (self->wsm.stage == 3) {
        if (self->ti_status) {
            self->wsm.stage = 0;
            return (false);
        }
        randomize_seed();
        if (!self->wsm.seed[0])
            sd = random_int(99999);
        self->wsm.universe = universe_create(size, self->input, sd, name);
        self->wsm.parent->title.data->universe = self->wsm.universe;
        (self->funcs.destroy)(self);
        return (true);
    }
    return (false);
}

bool creation_steps(menu_t *self)
{
    char *name = (self->wsm.stage == 1) ? "Enter world name" : "Enter seed";
    int fd = 0;

    if (self->wsm.stage == 1) {
        self->child = text_input_menu_create(self->wsm.name, 15, name, self);
        self->wsm.stage = 2;
        return (true);
    }
    if (self->wsm.stage == 2) {
        if (self->ti_status) {
            self->wsm.stage = 0;
            return (false);
        }
        if (!self->wsm.name[0]) {
            self->wsm.stage = 1;
            return (true);
        }
        self->child = text_input_menu_create(self->wsm.seed, 10, name, self);
        self->wsm.stage = 3;
        return (true);
    }
    return (creation_steps_next(self));
}

void world_select_menu_tick(menu_t *self)
{
    if (self->child) {
        (self->child->funcs.tick)(self->child);
        return;
    }
    input(self);
    if (self->wsm.stage > 0)
        if (creation_steps(self))
            return;
    if (self->input->escape.clicked) {
        self->wsm.parent->child = 0;
        (self->funcs.destroy)(self);
        return;
    }
    if (self->input->accept.clicked && self->wsm.selection > 0) {
        load_file(self);
    }
    if (self->input->accept.clicked && self->wsm.selection == 0) {
        self->wsm.stage = 1;
    }
}