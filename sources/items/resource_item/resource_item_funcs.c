/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "item_funcs.h"
#include "resources/resource_item.h"

const item_funcs_t resource_item_funcs =
{
    .draw_inventory = resource_item_draw_inventory,
    .draw_icon = resource_item_draw_icon,
    .get_tex = resource_item_get_tex,
    .interact_tile = resource_item_interact_tile,
    .is_depleted = resource_item_is_depleted,
    .get_name = resource_item_get_name
};