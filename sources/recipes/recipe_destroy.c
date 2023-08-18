/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void recipe_destroy(recipe_t *self)
{
    item_t *tmp = 0;

    (self->result->funcs.destroy)(self->result);
    while (self->cost) {
        tmp = self->cost->next;
        (self->cost->funcs.destroy)(self->cost);
        self->cost = tmp;
    }
    free(self);
}