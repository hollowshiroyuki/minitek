/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "tiles/tile.h"
#include "tiles_id.h"

#include "floor.h"
#include "screen.h"
#include "random.h"
#include "tiles/rock.h"

void rock_hurt(floor_t *floor, sfVector2i pos, entity_t *entity, int dmg)
{
    rock_damage(floor, pos, dmg);
}