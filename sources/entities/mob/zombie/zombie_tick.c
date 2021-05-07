/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/player.h"
#include "entities/mob.h"
#include "tiles/stair.h"
#include "screen.h"
#include "universe.h"
#include "tiles_id.h"
#include "resources/resources.h"
#include "random.h"
#include <stdio.h>

static void move(entity_t *self, sfVector2i off)
{
    sfVector2i dir;
    int speed = self->mob.tick_time & 1;
    sfVector2i n_pos = (sfVector2i){off.x * speed, off.y * speed};

    if (self->floor->player && self->mob.zom.walk_time == 0) {
        dir.x = self->floor->player->pos.x - self->pos.x;
        dir.y = self->floor->player->pos.y - self->pos.y;
        if (dir.x * dir.x + dir.y * dir.y < 50 * 50) {
            self->mob.zom.off.x = (dir.x < 0) ? -1 : self->mob.zom.off.x;
            self->mob.zom.off.x = (dir.x > 0) ? +1 : self->mob.zom.off.x;
            self->mob.zom.off.y = (dir.y < 0) ? -1 : self->mob.zom.off.y;
            self->mob.zom.off.y = (dir.y > 0) ? +1 : self->mob.zom.off.y;
        }
    }
    if (!(self->funcs.move)(self, n_pos) || random_int(50) == 0) {
        self->mob.zom.walk_time = 60;
        self->mob.zom.off.x = (random_int(3) - 1) * random_int(2);
        self->mob.zom.off.y = (random_int(3) - 1) * random_int(2);
    }
    self->mob.zom.walk_time -= (self->mob.zom.walk_time > 0) ? 1 : 0;
}

void zombie_tick(entity_t *self)
{
    mob_tick(self);
    move(self, self->mob.zom.off);
}