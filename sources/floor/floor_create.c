/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"
#include "floor.h"
#include "tiles_id.h"
#include "tiles/dirt.h"
#include "tiles/stair_down.h"

static maps_t floor_create_map(sfVector2i size, int depth)
{
    maps_t maps = {0};

    if (depth == 0) {
        maps = level_gen_create_and_validate_top_map(size.x, size.y);
    } else if (depth == 1) {
        maps = level_gen_create_and_validate_top_map(size.x, size.y);
    } else {
        depth -= 2;
        maps = level_gen_create_and_validate_und_map(size.x, size.y, depth);
    }
    return (maps);
}

void floor_link(floor_t *new, floor_t *par)
{
    for (int y = 0; y < par->size.y; y++) {
        for (int x = 0; x < par->size.x; x++) {
            if (floor_get_tile(par, (sfVector2i){x, y}).id != T_STAIRDOWN)
                continue;
            floor_set_tile(new, (sfVector2i){x, y}, stair_down, 0);
            floor_set_tile(new, (sfVector2i){x + 1, y}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x, y + 1}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x + 1, y + 1}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x - 1, y}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x, y - 1}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x - 1, y - 1}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x + 1, y - 1}, dirt, 0);
            floor_set_tile(new, (sfVector2i){x - 1, y + 1}, dirt, 0);
        }
    }
}

floor_t *floor_create(sfVector2i size, int depth, floor_t *parent)
{
    floor_t *new = malloc(sizeof(floor_t));
    maps_t maps = {0};

    if (!new)
        return (0);
    new->depth = depth;
    new->size = size;
    maps = floor_create_map(size, depth);
    new->tiles = maps.map;
    new->data = maps.data;
    new->tickCount = 0;
    if (parent) {
        floor_link(new, parent);
    }
    return (new);
}