/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "gui.h"
#include "menus/menu.h"
#include "screen.h"
#include "hsy.h"

void inventory_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i pos1 = (sfVector2i){1, 1};
    sfVector2i pos2 = (sfVector2i){12, 16};

    gui_frame_draw(screen, "Inventory", pos1, pos2);
}