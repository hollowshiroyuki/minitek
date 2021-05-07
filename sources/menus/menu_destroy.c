/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"

void menu_destroy(menu_t *self)
{
    if (self->name)
        free(self->name);
    if (self->child)
        (self->child->funcs.destroy)(self->child);
    free(self);
}