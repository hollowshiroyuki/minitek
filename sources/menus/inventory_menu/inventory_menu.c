/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "menu_funcs.h"

const menu_funcs_t inventory_menu_funcs =
{
    .init = menu_init,
    .tick = inventory_menu_tick,
    .draw = inventory_menu_draw,
    .destroy = menu_destroy
};