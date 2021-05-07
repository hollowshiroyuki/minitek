/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/player.h"

const entity_funcs_t player_funcs = {
    .draw = player_draw,
    .start_pos = player_start_pos,
    .tick = player_tick,
    .hurt_tile = player_hurt_tile,
    .can_swim = player_can_swim,
    .destroy = player_destroy,
    .touch_item = player_touch_item,
    .do_hurt = player_do_hurt
};