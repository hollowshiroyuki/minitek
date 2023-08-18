/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "gui.h"
#include "screen.h"

void tool_item_draw_inventory(item_t *self, screen_t *screen, sfVector2i pos)
{
    sfVector2i off_pos = (sfVector2i){pos.x + 8, pos.y};
    int tex = (self->funcs.get_tex)(self);

    screen_render_item(screen, pos, tex, 0);
    gui_text_draw(self->tool.name, screen, off_pos, sfWhite);
}