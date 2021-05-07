/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"

void text_input_menu_tick(menu_t *self)
{
    if (self->input->accept.clicked) {
        self->ti.parent->child = 0;
        self->ti.parent->ti_status = 0;
        (self->funcs.destroy)(self);
        return;
    }
    if (self->input->escape.clicked) {
        self->ti.buf[0] = '\0';
        self->ti.parent->child = 0;
        self->ti.parent->ti_status = 1;
        (self->funcs.destroy)(self);
    }
}