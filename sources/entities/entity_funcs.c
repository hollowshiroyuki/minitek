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
    .is_block_by = entity_is_block_by,
    .touch_item = entity_touch_item,
    .can_swim = entity_can_swim,
    .interact = entity_interact,
    .use = entity_use,
    .intersects = entity_intersects,
    .start_pos = entity_start_pos,
    .blocks = entity_blocks,
    .init = entity_init,
    .heal = entity_heal,
    .die = entity_die,
    .do_hurt = entity_do_hurt
};