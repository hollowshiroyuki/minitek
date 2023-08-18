/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

void entity_take(entity_t *self, entity_t *player)
{
    self->fur.player = player;
}