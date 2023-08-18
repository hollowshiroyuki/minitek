/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities/entity.h"
#include "inventory.h"

void player_destroy(entity_t *self)
{
    if (self->mob.pla.inventory)
        inventory_destroy(self->mob.pla.inventory);
    entity_destroy(self);
}