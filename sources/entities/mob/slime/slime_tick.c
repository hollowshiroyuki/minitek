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

static void move(entity_t *self)
{
    sfVector2i dir;
    sfVector2i n_pos = (sfVector2i){self->mob.sli.off.x, self->mob.sli.off.y};

    if (!(!(self->funcs.move)(self, n_pos) || random_int(20) == 0))
        return;
    if (self->mob.sli.jump_time <= -10) {
        self->mob.sli.off = (sfVector2i){random_int(3) - 1, random_int(3) - 1};
        if (self->floor->player) {
            dir.x = self->floor->player->pos.x - self->pos.x;
            dir.y = self->floor->player->pos.y - self->pos.y;
            if (dir.x * dir.x + dir.y * dir.y < 50 * 50) {
                self->mob.sli.off.x = (dir.x < 0) ? -1 : self->mob.sli.off.x;
                self->mob.sli.off.x = (dir.x > 0) ? +1 : self->mob.sli.off.x;
                self->mob.sli.off.y = (dir.y < 0) ? -1 : self->mob.sli.off.y;
                self->mob.sli.off.y = (dir.y > 0) ? +1 : self->mob.sli.off.y;
            }
        }
        if (self->mob.sli.off.x != 0 || self->mob.sli.off.y != 0)
            self->mob.sli.jump_time = 10;
    }
}

void slime_tick(entity_t *self)
{
    mob_tick(self);
    move(self);
    self->mob.sli.jump_time--;
    if (self->mob.sli.jump_time == 0) {
        self->mob.sli.off = (sfVector2i){0, 0};
    }
}