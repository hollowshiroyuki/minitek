/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

void mob_do_hurt(entity_t *self, int damage, int dir)
{
    if (self->mob.hurt_time)
        return;
    floor_add(self->floor, text_particle_create(damage, self->pos, sfRed));
    self->mob.health -= damage;
    if (dir == D_DOWN)
        self->mob.knockback.y = +6;
    if (dir == D_UP)
        self->mob.knockback.y = -6;
    if (dir == D_LEFT)
        self->mob.knockback.x = -6;
    if (dir == D_RIGHT)
        self->mob.knockback.x = +6;
    self->mob.hurt_time = 10;
}