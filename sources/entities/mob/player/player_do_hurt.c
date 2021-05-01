/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/player.h"

void player_do_hurt(entity_t *self, int damage, int dir)
{
    if (self->mob.hurt_time || self->mob.pla.invul)
        return;
    self->mob.health -= damage;
    if (dir == D_UP)
        self->mob.knockback.y = +6;
    if (dir == D_DOWN)
        self->mob.knockback.y = -6;
    if (dir == D_LEFT)
        self->mob.knockback.x = +6;
    if (dir == D_RIGHT)
        self->mob.knockback.x = -6;
    self->mob.hurt_time = 10;
    self->mob.pla.invul = 30;
}