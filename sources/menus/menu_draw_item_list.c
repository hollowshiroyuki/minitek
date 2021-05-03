/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "resources/item.h"
#include "screen.h"
#include "gui.h"
#include <stdio.h>

static void render_cursor(screen_t *scr, int select, bool a, sfVector2i pos)
{
    if (!a)
        return;
    screen_render_gui(scr, pos, 675, 0);
    gui_text_draw(">", scr, pos, sfWhite);
}

static int list_item_size(item_t *list)
{
    int i = 0;

    while (list) {
        list = list->next;
        i++;
    };
    return (i);
}

item_t *item_list_get(item_t *item, int pos)
{
    int i = 0;

    while (item) {
        if (i == pos) {
            return (item);
        }
        i++;
        item = item->next;
    }
    return (0);
}

void menu_draw_item_list(menu_t *self, screen_t *scr, int v[5], item_t *list)
{
    bool a = true;
    sfVector2i size = {v[2] - v[0], v[3] - v[1] - 1};
    sfVector2i pos;
    int i1 = list_item_size(list);
    int io = v[4] - size.y / 2;
    item_t *item;

    if (v[4] < 0) {
        v[4] = -v[4] - 1;
        a = false;
    }
    io = (io > i1 - size.y) ? (i1 - size.y) : io;
    io = (io < 0) ? 0 : io;
    i1 = (i1 > size.y) ? size.y : i1;
    for (int i = 0; i < i1; i++) {
        item = item_list_get(list, i + io);
        pos = (sfVector2i){(1 + v[0]) * 8, (i + 1 + v[1]) * 8};
        (*item->funcs.draw_inventory)(item, scr, pos);
    }
    render_cursor(scr, v[4], a, (sfVector2i){v[0] * 8, (v[4] + 1 - io + v[1]) * 8});
}