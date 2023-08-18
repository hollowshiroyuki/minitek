/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "item_funcs.h"

const item_funcs_t item_funcs =
{
    .get_tex = item_get_tex,
    .on_take = item_on_take,
    .draw_inventory = item_draw_inventory,
    .interact = item_interact,
    .interact_tile = item_interact_tile,
    .is_depleted = item_is_depleted,
    .can_attack = item_can_attack,
    .attack_bonus = item_attack_bonus,
    .get_name = item_get_name,
    .matches = item_matches
};