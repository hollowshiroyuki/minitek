/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities/entity.h"

void furniture_destroy(entity_t *self)
{
    free(self->fur.name);
    entity_destroy(self);
}