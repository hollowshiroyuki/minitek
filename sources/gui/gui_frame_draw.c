/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "screen.h"
#include "gui.h"
#include "hsy.h"

static void draw_borders(screen_t *s, sfVector2i p, sfVector2i t, sfVector2i b)
{
    sfVector2i p_off= (sfVector2i){p.x * 8, p.y * 8};

    if ((p.x == t.x && p.y == t.y) || (p.x == b.x && p.y == b.y)) {
        screen_render_gui(s, p_off, 672, (p.x == t.x && p.y == t.y) ? 0 : 3);
        return;
    }
    if ((p.x == t.x && p.y == b.y) || (p.x == b.x && p.y == t.y)) {
        screen_render_gui(s, p_off, 672, (p.x == t.x && p.y == b.y) ? 2 : 1);
        return;
    }
    if (p.x == t.x || p.x == b.x) {
        screen_render_gui(s, p_off, 21 * 32 + 2, (p.x == b.x) ? HOR_F : 0);
        return;
    }
    if (p.y == t.y || p.y == b.y) {
        screen_render_gui(s, p_off, 21 * 32 + 1, (p.y == b.y) ? VER_F : 0);
        return;
    }
    screen_render_gui(s, p_off, 21 * 32 + 3, 0);
}

static void draw_frame(screen_t *s, sfVector2i p1, sfVector2i p2)
{
    for (int y = p1.y; y <= p2.y; y++) {
        for (int x = p1.x; x <= p2.x; x++) {
            draw_borders(s, (sfVector2i){x, y}, p1, p2);
        }
    }
}

void gui_frame_draw(screen_t *s, char *name, sfVector2i p1, sfVector2i p2)
{
    draw_frame(s, p1, p2);
    for (unsigned long i = 1; i <= hsy_strlen(name); i++)
        screen_render_gui(s, (sfVector2i){i * p1.x * 8 + 8, p1.y * 8}, 675, 0);
    gui_text_draw(name, s, (sfVector2i){p1.x * 8 + 8, p1.y * 8}, sfWhite);
}