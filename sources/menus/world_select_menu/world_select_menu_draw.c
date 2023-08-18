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
#include "menus/world_select_menu.h"
#include <stdio.h>

static void draw_entry(screen_t *scr, world_entry_t *ent, sfVector2i p, int i)
{
    sfColor color = sfWhite;

    if (ent->error)
        color = sfRed;
    gui_text_draw(ent->name, scr, p, color);
}

void world_select_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i pos1 = (sfVector2i){1, 1};
    sfVector2i pos2 = (sfVector2i){14, 16};
    sfVector2i cur;

    gui_frame_draw(screen, "Saves", pos1, pos2);
    for (int i = 0; i < 20 && self->wsm.worlds[i]; i++) {
        cur = (sfVector2i){16, (2 + i) * 8};
        draw_entry(screen, self->wsm.worlds[i], cur, i);
    }
    cur = (sfVector2i){pos1.x * 8, (pos1.y + 1 + self->wsm.selection) * 8};
    screen_render_gui(screen, cur, 675, 0);
    gui_text_draw(">", screen, cur, sfWhite);
    if (self->child)
        (self->child->funcs.draw)(self->child, screen);
}