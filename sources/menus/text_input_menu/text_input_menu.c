/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "menu_funcs.h"

const menu_funcs_t text_input_menu_funcs =
{
    .init = menu_init,
    .tick = text_input_menu_tick,
    .draw = text_input_menu_draw,
    .destroy = text_input_menu_destroy,
    .draw_item_list = menu_draw_item_list
};