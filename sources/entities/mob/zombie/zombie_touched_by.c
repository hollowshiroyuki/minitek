/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/slime.h"
#include "screen.h"
#include <stdio.h>
#include "entities_id.h"

void zombie_touched_by(entity_t *self, entity_t *entity)
{
    int dmg = self->mob.zom.level + 2;

    if (entity->id == E_MOB && entity->mob.id == MB_PLAYER) {
        (entity->funcs.hurt)(entity, self, dmg, self->mob.dir);
    }
}