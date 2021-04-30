/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

void mob_hurt_tile(entity_t *self, tile_t tile, sfVector2i pos, int dmg)
{
    mob_do_hurt(self, dmg, self->mob.dir);
}