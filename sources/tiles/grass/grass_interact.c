/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "tiles/tile.h"
#include "tiles_id.h"
#include "index_til.h"
#include "entities/entity.h"
#include "floor.h"
#include "resources/item.h"
#include "items_id.h"
#include "screen.h"
#include "random.h"
#include "tiles/dirt.h"
#include "tiles/farmland.h"
#include "resources/resources.h"

static void shovel(tile_t *self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    item_t *item = e->mob.pla.active_item;
    sfVector2i drop_pos;
    entity_t *ie;
    item_t *drop;

    drop_pos.x = pos.x * 16 + random_int(10) + 3;
    drop_pos.y = pos.y * 16 + random_int(10) + 3;
    if (player_pay_stamina(e, 4 - item->tool.level)) {
        floor_set_tile(floor, pos, dirt, 0);
        if (random_int(5) == 0) {
            drop = resource_item_create((resource_t *)&r_seeds, 1);
            ie = item_entity_create(drop, drop_pos);
            floor_add(floor, ie);
        }
    }
}

static void hoe(tile_t *self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    item_t *item = e->mob.pla.active_item;
    sfVector2i drop_pos;
    entity_t *ie;
    item_t *drop;

    drop_pos.x = pos.x * 16 + random_int(10) + 3;
    drop_pos.y = pos.y * 16 + random_int(10) + 3;
    if (player_pay_stamina(e, 4 - item->tool.level)) {
        floor_set_tile(floor, pos, farmland, 0);
        if (random_int(5) == 0) {
            drop = resource_item_create((resource_t *)&r_seeds, 1);
            ie = item_entity_create(drop, drop_pos);
            floor_add(floor, ie);
        }
    }
}

bool grass_interact(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    item_t *item = e->mob.pla.active_item;

    if (item->id != I_TOOL)
        return (false);
    if (item->tool.type->id == shovel_type.id) {
        shovel(&self, floor, pos, e);
        return (true);
    }
    if (item->tool.type->id == hoe_type.id) {
        hoe(&self, floor, pos, e);
        return (true);
    }
    return (false);
}