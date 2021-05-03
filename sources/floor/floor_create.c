/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "level_gen.h"
#include "floor.h"
#include "tiles_id.h"
#include "tiles/dirt.h"
#include "tiles/stair_down.h"
#include "consts.h"

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

void init_entities(floor_t *self, int ept)
{
    sfVector2i size = self->size;

    self->entities = 0;
    self->entities_in_tiles = malloc(sizeof(entity_t **) * size.x * size.y);
    for (int i = 0; i < size.x * size.y; i++) {
        self->entities_in_tiles[i] = malloc(sizeof(entity_t *) * (ept + 1));
        memset(self->entities_in_tiles[i], 0, sizeof(entity_t *) * (ept + 1));
    }
    self->entities_row = malloc(sizeof(entity_t *) * (ept * size.x + 1));
    memset(self->entities_row, 0, sizeof(entity_t *) * (ept * size.x + 1));
    floor_try_spawn(self, 5000);
}

floor_t *floor_create(sfVector2i size, int depth, floor_t *parent)
{
    floor_t *new = malloc(sizeof(floor_t));
    maps_t maps = {0};

    if (!new)
        return (0);
    memset(new, 0, sizeof(floor_t));
    new->depth = depth;
    new->player = 0;
    new->size = size;
    maps = floor_create_map(size, depth);
    new->tiles = maps.map;
    new->data = maps.data;
    new->tickCount = 0;
    new->monster_density = 16;
    if (parent) {
        floor_link(new, parent);
    }
    init_entities(new, entities_per_tile);
    return (new);
}