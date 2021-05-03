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

static void calc_select(int *select, bool *draw_cursor)
{
    if (*select < 0) {
        *select = -(*select) - 1;
        *draw_cursor = false;
    }
}

static void render_cursor(screen_t *scr, int select, sfIntRect r, int itm_off)
{
    sfVector2i pos = (sfVector2i){r.left, select + 1 - itm_off + r.top};

    pos = (sfVector2i){pos.x * 8, pos.y * 8};
    screen_render_gui(scr, pos, 675, 0);
    gui_text_draw(">", scr, pos, sfWhite);
}

void menu_draw_item_list(menu_t *self, screen_t *scr, int v[5], item_t *list)
{
    sfIntRect r = (sfIntRect){v[0], v[1], v[2] - v[0], v[3] - v[1] - 1};
    bool draw_cursor = (item_list_size(list)) ? true : false;
    int select = v[4];
    int l_len = ((l_len = item_list_size(list)) > r.height) ? r.height : l_len;
    int itm_off = select - r.height / 2;
    sfVector2i pos;
    item_t *item;

    calc_select(&draw_cursor, &select);
    if (itm_off > item_list_size(list) - r.height)
        itm_off = item_list_size(list) - r.height;
    itm_off = (itm_off < 0) ? 0 : itm_off;
    for (int i = 0; i < l_len; i++) {
        item = item_list_get(list, i + itm_off);
        pos = (sfVector2i){(1 + r.left) * 8, (i + 1 + r.top) * 8};
        (*item->funcs.draw_inventory)(item, scr, pos);
    }
    if (draw_cursor)
        render_cursor(scr, select, r, itm_off);
}