/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "entities/entity.h"
#include "floor.h"
#include <stdio.h>

void cactus_bump(tile_t self, floor_t *floor, sfVector2i pos, entity_t *entity)
{
    (entity->funcs.hurt_tile)(entity, self, pos, 1);
}