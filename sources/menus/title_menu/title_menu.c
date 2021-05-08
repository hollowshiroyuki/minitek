/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "menu_funcs.h"

const menu_funcs_t title_menu_funcs =
{
    .init = menu_init,
    .tick = title_menu_tick,
    .draw = title_menu_draw,
    .destroy = title_menu_destroy,
    .draw_item_list = menu_draw_item_list
};