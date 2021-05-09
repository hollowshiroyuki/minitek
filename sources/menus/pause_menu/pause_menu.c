/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "menu_funcs.h"

const menu_funcs_t pause_menu_funcs =
{
    .init = menu_init,
    .tick = pause_menu_tick,
    .draw = pause_menu_draw,
    .draw_item_list = menu_draw_item_list,
    .destroy = menu_destroy
};