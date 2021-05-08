/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "universe.h"
#include "level_gen.h"
#include <stdio.h>
#include "floor.h"

void universe_destroy(universe_t *self)
{
    if (!self)
        return;
    for (int i = 0; self->floors[i]; i++) {
        floor_destroy(self->floors[i]);
    }
    if (self->player) {
        (*self->player->funcs.destroy)(self->player);
    }
    if (self->menu)
        (*self->menu->funcs.destroy)(self->menu);
    if (self->craft)
        craft_destroy(self->craft);
    if (self->name)
        free(self->name);
    free(self);
}