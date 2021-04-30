/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

static void knockback(entity_t *self)
{
    mob_t *mob = &self->mob;

    if (mob->knockback.x < 0) {
            (*self->funcs.move_axis)(self, (sfVector2i){-1, 0});
            mob->knockback.x++;
    }
    if (mob->knockback.x > 0) {
            (*self->funcs.move_axis)(self, (sfVector2i){1, 0});
            mob->knockback.x--;
    }
    if (mob->knockback.y < 0) {
            (*self->funcs.move_axis)(self, (sfVector2i){0, -1});
            mob->knockback.y++;
    }
    if (mob->knockback.y > 0) {
            (*self->funcs.move_axis)(self, (sfVector2i){0, 1});
            mob->knockback.y--;
    }
}

static void direction(entity_t *self, sfVector2i pos)
{
    if (pos.x || pos.y) {
        self->mob.walk_dist++;
        self->mob.dir = (pos.x < 0) ? D_LEFT : self->mob.dir;
        self->mob.dir = (pos.x > 0) ? D_RIGHT : self->mob.dir;
        self->mob.dir = (pos.y < 0) ? D_UP : self->mob.dir;
        self->mob.dir = (pos.y > 0) ? D_DOWN : self->mob.dir;
    }
}

bool mob_move(entity_t *self, sfVector2i pos)
{
    if (mob_is_swimming(self) && self->mob.swim_time++ % 4 == 0)
        return (true);
    knockback(self);
    if (self->mob.hurt_time)
        return (true);
    direction(self, pos);
    return (entity_move(self, pos));
}