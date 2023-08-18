/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/player.h"
#include "universe.h"

void player_change_floor(entity_t *self, int dir)
{
    self->mob.pla.universe->floor_change = dir;
}