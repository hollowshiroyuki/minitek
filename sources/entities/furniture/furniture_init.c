/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "hsy.h"

void furniture_init(entity_t *self, char *name)
{
    self->fur.name = hsy_strdup(name);
    self->box.x = 3;
    self->box.y = 3;
}