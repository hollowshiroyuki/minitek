/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"
#include "resources/item.h"
#include "screen.h"

void floor_change_menu_draw(menu_t *self, screen_t *screen)
{
    screen_render_gui(screen, (sfVector2i){0, 0}, 54, 0);
}