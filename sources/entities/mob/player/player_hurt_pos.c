/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities/entity.h"
#include "entities_id.h"

void player_hurt_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2)
{
    entity_t **es = floor_get_entities(self->floor, pos1, pos2);
    int dir = self->mob.dir;
    int dmg = 0;

    for (int i = 0; es[i]; i++) {
        if (es[i]->id != E_PLAYER) {
            dmg = player_get_attack_damage(self, es[i]);
            (*es[i]->funcs.hurt)(es[i], self, dmg, dir);
        }
    }
    free(es);
}