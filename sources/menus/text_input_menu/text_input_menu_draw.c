/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "gui.h"
#include "menus/menu.h"
#include "entities/entity.h"
#include "screen.h"
#include "hsy.h"
#include <stdio.h>

void text_input_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i pos1 = (sfVector2i){2, 10};
    sfVector2i pos2 = (sfVector2i){pos1.x + 24, pos1.y + 2};

    gui_frame_draw(screen, self->name, pos1, pos2);
    pos1 = (sfVector2i){(pos1.x + 1) * 8, (pos1.y + 1) * 8};
    gui_text_draw(self->ti.buf, screen, pos1, sfWhite);
    pos1.x = (pos1.x + 1 + hsy_strlen(self->ti.buf) * 8);
    screen_render_gui(screen, pos1, 4 * 32 + 3, 0);
}