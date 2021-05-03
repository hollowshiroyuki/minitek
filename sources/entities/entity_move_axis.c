/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"

static void calc_to(entity_t *self, sfVector2i pos, int to[8])
{
    to[0] = (self->pos.x - self->box.x) >> 4;
    to[1] = (self->pos.y - self->box.y) >> 4;
    to[2] = (self->pos.x + self->box.x) >> 4;
    to[3] = (self->pos.y + self->box.y) >> 4;
    to[4] = ((self->pos.x + pos.x) - self->box.x) >> 4;
    to[5] = ((self->pos.y + pos.y) - self->box.y) >> 4;
    to[6] = ((self->pos.x + pos.x) + self->box.x) >> 4;
    to[7] = ((self->pos.y + pos.y) + self->box.y) >> 4;
}

static bool tile_interaction(entity_t *self, sfVector2i pos, int to[0])
{
    tile_t t = {0};
    sfVector2i c = {0};

    for (int yt = to[5]; yt <= to[7]; yt++) {
        for (int xt = to[4]; xt <= to[6]; xt++) {
            if (xt >= to[0] && xt <= to[2] && yt >= to[1] && yt <= to[3])
                continue;
            t = floor_get_tile(self->floor, (sfVector2i){xt, yt});
            c = (sfVector2i){xt, yt};
            if (t.bump)
                (*t.bump)(t, self->floor, c, self);
            if (t.may_pass && !(*t.may_pass)(t, self->floor, c, self)) {
                return (true);
            }
        }
    }
    return (false);
}

static bool entity_interaction(entity_t *self, sfVector2i pos, int to[0])
{
    return (false);
}

bool entity_move_axis(entity_t *self, sfVector2i pos)
{
    int to[8] = {0};

    if (pos.x && pos.y)
        return (false);
    calc_to(self, pos, to);
    if (tile_interaction(self, pos, to))
        return (false);
    if (entity_interaction(self, pos, to))
        return (false);
    self->pos.x += pos.x;
    self->pos.y += pos.y;
    return (true);
}