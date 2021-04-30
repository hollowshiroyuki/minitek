/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"

bool mob_is_swimming(entity_t *self)
{
    sfVector2i tile_pos = (sfVector2i){self->pos.x >> 4, self->pos.y >> 4};
    tile_t tile = floor_get_tile(self->floor, tile_pos);

    return (tile.id == T_LAVA || tile.id == T_WATER);
}