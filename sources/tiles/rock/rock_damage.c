/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include "tiles/tile.h"
#include "tiles_id.h"

#include "entities/entity.h"
#include "floor.h"
#include "screen.h"
#include "random.h"
#include "resources/resources.h"
#include "tiles/dirt.h"

void rock_break(floor_t *floor, sfVector2i pos, int count1, int count2)
{
    sfVector2i i_pos;
    entity_t *i_entity;
    item_t *item;

    for (int i = 0; i < count1; i++) {
        i_pos.x = pos.x * 16 + random_int(10) + 3;
        i_pos.y = pos.y * 16 + random_int(10) + 3;
        item = resource_item_create((resource_t *)&r_stone, 1);
        i_entity = item_entity_create(item, i_pos);
        floor_add(floor, i_entity);
    }
    for (int i = 0; i < count2; i++) {
        i_pos.x = pos.x * 16 + random_int(10) + 3;
        i_pos.y = pos.y * 16 + random_int(10) + 3;
        item = resource_item_create((resource_t *)&r_stone, 1);
        i_entity = item_entity_create(item, i_pos);
        floor_add(floor, i_entity);
    }
    floor_set_tile(floor, pos, dirt, 0);
}

void rock_damage(floor_t *floor, sfVector2i pos, int dmg)
{
    int damage = floor_get_data(floor, pos) + dmg;
    int stone_drop = random_int(4) + 1;
    int coal_drop = random_int(2);
    sfVector2i p_pos = (sfVector2i){pos.x * 16, pos.y * 16};

    floor_add(floor, text_particle_create(dmg, p_pos, sfRed));
    if (damage > 50) {
        rock_break(floor, pos, stone_drop, coal_drop);
    } else {
        floor_set_data(floor, pos, damage);
    }
}