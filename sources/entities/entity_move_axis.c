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

    for (int y = to[5]; y < to[7]; y++) {
        for (int x = to[4]; x < to[6]; x++) {
            if (x >= to[0] && x <= to[2] && y >= to[1] && y <= to[3])
                continue;
            t = floor_get_tile(self->floor, (sfVector2i){x, y});
            c = (sfVector2i){x, y};
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