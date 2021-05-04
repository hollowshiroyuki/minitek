/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities/entity.h"
#include "entities_id.h"

bool player_interact_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2)
{
    entity_t **es = floor_get_entities(self->floor, pos1, pos2);
    int dir = self->mob.dir;
    item_t *item = self->mob.pla.active_item;

    for (int i = 0; es[i]; i++) {
        if (es[i]->id == E_PLAYER)
            continue;
        if ((*es[i]->funcs.interact)(es[i], self, item, dir)) {
            free(es);
            return (true);
        }
    }
    return (false);
}