/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"

void world_select_menu_destroy(menu_t *self)
{
    for (int i = 0; i < 20 && self->wsm.worlds[i]; i++) {
        free(self->wsm.worlds[i]);
    }
    self->wsm.parent->child = 0;
    menu_destroy(self);
}