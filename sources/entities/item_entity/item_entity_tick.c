/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/item_entity.h"

static void calc_next_pos(entity_t *self)
{
    sfVector2i o = {self->pos.x, self->pos.y};
    sfVector2i n;
    sfVector2i exp;
    sfVector2i got;

    self->itm.b.x += self->itm.a.x;
    self->itm.b.y += self->itm.a.y;
    self->itm.b.z += self->itm.a.z;
    if (self->itm.b.z < 0) {
        self->itm.b.z = 0;
        self->itm.a.x *= 0.6;
        self->itm.a.y *= 0.6;
        self->itm.a.z *= -0.5;
    }
    n = (sfVector2i){(int)self->itm.b.x, (int)self->itm.b.y};
    exp = (sfVector2i){n.x - o.x, n.y - o.y};
    (self->funcs.move)(self, exp);
    got = (sfVector2i){self->pos.x - o.x, self->pos.y - o.y};
    self->itm.b = (sfVector3f){got.x - exp.x, got.y - exp.y, self->itm.b.z};
}

void item_entity_tick(entity_t *self)
{
    self->itm.time++;
    if (self->itm.time >= self->itm.lifetime) {
        self->removed = true;
        return;
    }
    //calc_next_pos(self);
}