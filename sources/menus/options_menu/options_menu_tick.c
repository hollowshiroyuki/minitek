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
        self->opt.selection--;
    if (self->input->down.clicked)
        self->opt.selection++;
    if (self->opt.selection < C_COUNT)
        self->opt.selection += C_COUNT;
    if (self->opt.selection >= C_COUNT)
        self->opt.selection -= C_COUNT;
}

static void normal(menu_t *self)
{
    input(self);
    if (self->input->escape.clicked && self->opt.save_next == false) {
        self->opt.parent->child = 0;
        (self->funcs.destroy)(self);
        return;
    }
    if (self->input->accept.clicked)
        self->opt.save_next = true;
}

static void save(menu_t *self)
{
    mkey_t *key = &self->input->keys[self->opt.selection];

    self->opt.save_next = false;
    mkey_init(key, self->input->tmp.code, key->id);
}

void options_menu_tick(menu_t *self)
{
    if (!self->opt.save_next) {
        normal(self);
        return;
    }
    if (self->opt.save_next) {
        if (self->input->escape.clicked) {
            self->opt.save_next = false;
            return;
        }
        for (int i = 0; i < C_COUNT; i++)
            if (self->input->keys[i].code == self->input->tmp.code)
                return;
        save(self);
    }
}