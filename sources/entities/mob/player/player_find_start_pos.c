/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include "entities/entity.h"
#include "entities/player.h"
#include "floor.h"
#include "random.h"
#include "tiles_id.h"

bool player_find_start_pos(entity_t *self, floor_t *floor)
{
    sfVector2i pos = {0};

    while (true) {
        pos.x = random_int(floor->size.x);
        pos.y = random_int(floor->size.y);
        if (floor_get_tile(floor, pos).id == T_GRASS) {
            self->pos.x = pos.x * 16 + 8;
            self->pos.y = pos.y * 16 + 8;
            return (true);
        }
    }
}