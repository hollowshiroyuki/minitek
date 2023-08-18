/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "item_funcs.h"
#include "resources/furniture_item.h"

const item_funcs_t furniture_item_funcs =
{
    .draw_inventory = furniture_item_draw_inventory,
    .draw_icon = furniture_item_draw_icon,
    .get_tex = furniture_item_get_tex,
    .interact_tile = furniture_item_interact_tile,
    .is_depleted = furniture_item_is_depleted,
    .get_name = furniture_item_get_name,
    .can_attack = furniture_item_can_attack,
    .destroy = furniture_item_destroy
};