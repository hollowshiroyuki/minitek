/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void craft_destroy(craft_t *self)
{
    recipe_list_destroy(self->workbench);
    free(self);
}