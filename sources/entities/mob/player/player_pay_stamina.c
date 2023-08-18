/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

bool player_pay_stamina(entity_t *self, int cost)
{
    if (cost > self->mob.pla.stamina)
        return (false);
    self->mob.pla.stamina -= cost;
    return (true);
}