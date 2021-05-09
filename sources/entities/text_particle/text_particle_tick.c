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

void text_particle_tick(entity_t *self)
{
    self->tpart.time++;
    if (self->tpart.time > 60)
        self->removed = true;
    self->tpart.b.x += self->tpart.a.x;
    self->tpart.b.y -= self->tpart.a.y;
    self->tpart.b.z += self->tpart.a.z;
    if (self->tpart.b.z < 0) {
        self->tpart.b.z = 0;
        self->tpart.a.z *= -0.5;
        self->tpart.a.x *= 0.6;
        self->tpart.a.y *= 0.6;
    }
    self->tpart.a.z -= -0.005;
    self->pos.x = self->tpart.b.x;
    self->pos.y = self->tpart.b.y;
}