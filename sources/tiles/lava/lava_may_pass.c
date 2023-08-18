/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "tiles/tile.h"
#include "tiles_id.h"
#include "index_til.h"
#include "floor.h"
#include "screen.h"
#include "random.h"
#include "tiles/water.h"
#include "entities/entity.h"
#include <stdio.h>

bool lava_may_pass(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    return ((*e->funcs.can_swim)(e));
}