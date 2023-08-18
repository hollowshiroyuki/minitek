/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

const entity_funcs_t entity_funcs = {
    .tick = entity_tick,
    .draw = entity_draw,
    .destroy = entity_destroy,
    .hurt = entity_hurt,
    .hurt_tile = entity_hurt_tile,
    .move = entity_move,
    .move_axis = entity_move_axis,
    .touched_by = entity_touched_by,
    .is_blockable_by = entity_is_blockable_by,
    .touch_item = entity_touch_item,
    .can_swim = entity_can_swim,
    .interact = entity_interact,
    .use = entity_use,
    .instance_of = entity_instance_of,
    .intersects = entity_intersects
};