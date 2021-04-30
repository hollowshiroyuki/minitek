/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

void mob_hurt(entity_t *self, entity_t *mob, int damage, int dir)
{
    mob_do_hurt(self, damage, dir);
}