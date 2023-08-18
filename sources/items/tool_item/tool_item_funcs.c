/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "item_funcs.h"
#include "resources/tool_item.h"

const item_funcs_t tool_item_funcs =
{
    .matches = tool_item_matches,
    .attack_bonus = tool_item_attack_bonus,
    .can_attack = tool_item_can_attack,
    .draw_inventory = tool_item_draw_inventory,
    .draw_icon = tool_item_draw_icon,
    .get_tex = tool_item_get_tex
};