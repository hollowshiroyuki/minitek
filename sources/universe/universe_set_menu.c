/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "menus/menu.h"
#include "menu_funcs.h"

void universe_set_menu(universe_t *self, menu_t *menu)
{
    self->menu = menu;
    if (menu)
        (menu->funcs.init)(menu, self, self->input);
}