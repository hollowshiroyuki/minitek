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

void slime_touched_by(entity_t *self, entity_t *entity)
{
    int dmg = self->mob.sli.level + 1;

    if (entity->id == E_MOB && entity->mob.id == E_PLAYER) {
        (entity->funcs.hurt)(entity, self, dmg, self->mob.dir);
    }
}