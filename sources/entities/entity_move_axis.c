/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <stdlib.h>
#include "entities/entity.h"
#include "entities_id.h"

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

static bool entity_interaction(entity_t *self, sfVector2i pos, sfVector2i b[4])
{
    bool ret = false;
    entity_t **was_inside = floor_get_entities(self->floor, b[0], b[1]);
    entity_t **is_inside = floor_get_entities(self->floor, b[2], b[3]);

    for (int i = 0; is_inside[i]; i++) {
        if (is_inside[i] == self)
            continue;
        (*is_inside[i]->funcs.touched_by)(is_inside[i], self);
    }
    entities_remove_all(is_inside, was_inside);
    for (int i = 0; !ret && is_inside[i]; i++) {
        if (is_inside[i] == self)
            continue;
        if ((*is_inside[i]->funcs.blocks)(is_inside[i], self))
            ret = true;
    }
    free(was_inside);
    free(is_inside);
    return (ret);
}

void calc_boxes(sfVector2i boxes[4], entity_t *self, sfVector2i pos)
{
    sfVector2i p = self->pos;
    sfVector2i b = self->box;

    boxes[0] = (sfVector2i){p.x - b.x, p.y - b.y};
    boxes[1] = (sfVector2i){p.x + b.x, p.y + b.y};
    boxes[2] = (sfVector2i){p.x + pos.x - b.x, p.y + pos.y - b.y};
    boxes[3] = (sfVector2i){p.x + pos.x + b.x, p.y + pos.y + b.y};
}

bool entity_move_axis(entity_t *self, sfVector2i pos)
{
    int to[8] = {0};
    sfVector2i boxes[4];

    if (pos.x && pos.y)
        return (false);
    calc_to(self, pos, to);
    calc_boxes(boxes, self, pos);
    if (tile_interaction(self, pos, to))
        return (false);
    if (entity_interaction(self, pos, boxes))
        return (false);
    self->pos.x += pos.x;
    self->pos.y += pos.y;
    return (true);
}