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

static void draw_entry(mkey_t i, screen_t *scr, sfVector2i pos, sfVector2i s)
{
    sfVector2i r_pos;

    r_pos.x = (s.x - hsy_strlen(keys_strings[i.code])) * 8;
    r_pos.y = pos.y;
    gui_text_draw((char *)controls_strings[i.id], scr, pos, sfWhite);
    gui_text_draw((char *)keys_strings[i.code], scr, r_pos, sfWhite);
}

void options_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i pos1 = (sfVector2i){1, 1};
    sfVector2i pos2 = (sfVector2i){14, 16};
    sfVector2i cur;

    gui_frame_draw(screen, "Controls", pos1, pos2);
    for (int i = 0; i < C_COUNT; i++) {
        cur = (sfVector2i){16, (2 + i) * 8};
        draw_entry(self->input->keys[i], screen, cur, pos2);
    }
    cur = (sfVector2i){pos1.x * 8, (pos1.y + 1 + self->opt.selection) * 8};
    screen_render_gui(screen, cur, 675, 0);
    gui_text_draw(">", screen, cur, sfWhite);
    if (self->opt.save_next) {
        pos1 = (sfVector2i){pos1.x, pos2.y + 2};
        pos2 = (sfVector2i){pos2.x + 14, pos2.y + 4};
        gui_frame_draw(screen, "", pos1, pos2);
        pos1 = (sfVector2i){(pos1.x + 1) * 8, (pos1.y + 1) * 8};
        gui_text_draw("Choose a key or press Esc.", screen, pos1, sfWhite);
    }
}