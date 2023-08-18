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

void about_menu_tick(menu_t *self)
{
    if (self->input->menu.clicked || self->input->escape.clicked) {
        self->about.parent->child = NULL;
        (self->funcs.destroy)(self);
        return;
    }
}