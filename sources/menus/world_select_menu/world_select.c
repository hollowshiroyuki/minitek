/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "menu_funcs.h"

const menu_funcs_t world_select_menu_funcs =
{
    .init = menu_init,
    .tick = world_select_menu_tick,
    .draw = world_select_menu_draw,
    .destroy = world_select_menu_destroy,
    .draw_item_list = menu_draw_item_list
};