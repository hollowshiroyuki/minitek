/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities/entity.h"
#include "entities_id.h"
#include <stdio.h>

bool player_use_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2)
{
    entity_t **es = floor_get_entities(self->floor, pos1, pos2);
    int dir = self->mob.dir;

    for (int i = 0; es[i]; i++) {
        if (es[i]->id != E_PLAYER && (*es[i]->funcs.use)(es[i], self, dir)) {
            free(es);
            return (true);
        }
    }
    free(es);
    return (false);
}