/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

void mob_tick(entity_t *self)
{
    mob_t *mob = &self->mob;
    sfVector2i tile = (sfVector2i){self->pos.x >> 4, self->pos.y >> 4};

    mob->tick_time++;
    if (floor_get_tile(self->floor, tile).id == T_LAVA) {
        mob_hurt(self, self, 4, mob->dir);
    }
    if (self->mob.health <= 0) {
        self->removed = true;
        (self->funcs.die)(self);
    }
    if (mob->hurt_time)
        mob->hurt_time--;
}