/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities_id.h"

void furniture_touched_by(entity_t *self, entity_t *entity)
{
    bool is_player = entity->id == E_MOB && entity->mob.id == MB_PLAYER;

    if (is_player && self->fur.push_time == 0) {
        self->fur.push_dir = entity->mob.dir;
        self->fur.push_time = 10;
    }
}