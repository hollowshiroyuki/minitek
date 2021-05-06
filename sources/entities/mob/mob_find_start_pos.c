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

static bool is_in_cam(sfVector2i p_pos, sfVector2i m_pos)
{
    sfVector2i in_view;

    in_view.x = p_pos.x - m_pos.x;
    in_view.y = p_pos.y - m_pos.y;
    if (in_view.x * in_view.x + in_view.y * in_view.y < 80 * 80)
        return (true);
    return (false);
}

static bool near_entities(floor_t *floor, sfVector2i pos, int r)
{
    bool near = false;
    sfVector2i pos1 = (sfVector2i){pos.x - r, pos.y - r};
    sfVector2i pos2 = (sfVector2i){pos.x + r, pos.y + r};
    entity_t **list = floor_get_entities(floor, pos1, pos2);

    if (list[0])
        near = true;
    free(list);
    return (near);
}

bool mob_find_start_pos(entity_t *self, floor_t *floor)
{
    sfVector2i pos;
    sfVector2i pos2;
    tile_t tile = {0};

    pos.x = random_int(floor->size.x);
    pos.y = random_int(floor->size.y);
    pos2.x = pos.x * 16 + 8;
    pos2.y = pos.y * 16 + 8;
    if (floor->player && is_in_cam(floor->player->pos, pos2))
        return (false);
    if (near_entities(floor, pos2, floor->monster_density * 16))
        return (false);
    tile = floor_get_tile(floor, pos);
    if (!tile.may_pass || (*tile.may_pass)(tile, floor, pos, self)) {
        self->pos = pos2;
        return (true);
    }
    return (false);
}