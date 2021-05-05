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
#include "items_id.h"
#include "screen.h"
#include "hsy.h"

const char *death_menu_entries[] = {
    "Revive !",
    "Quit to Menu",
    "Quit"
};

static void frame_draw(menu_t *self, screen_t *scr, sfVector2i o, sfVector2i s)
{
    sfVector2i pos2 = (sfVector2i){o.x + s.x, o.y + s.y};

    gui_frame_draw(scr, "", o, pos2);
}

static void print_entries(screen_t *screen, int selection, sfVector2i o)
{
    char entry[20] = {0};
    sfColor color = sfWhite;
    sfVector2i pos;

    for (int i = 0; i < 3; i++) {
        color = sfWhite;
        if (i == selection) {
            hsy_strcat(entry, "> ");
            hsy_strcat(entry, death_menu_entries[i]);
            hsy_strcat(entry, "  ");
            color = sfYellow;
        } else
            hsy_strcat(entry, death_menu_entries[i]);
        pos.x = ((o.x * (5 * 8)) - hsy_strlen(entry) * 8) / 2;
        pos.y = (o.y + 4 + i) * 8;
        gui_text_draw(entry, screen, pos, color);
        entry[0] = '\0';
    }
}

void death_menu_draw(menu_t *self, screen_t *screen)
{
    int select = self->dea.selection;
    sfVector2i size = (sfVector2i){20, 7};
    sfVector2i o = (sfVector2i){screen->size.x / 8 / 2 - size.x / 2, 0};
    sfVector2i msg_p;

    o.y = (screen->size.y / 8) / 2 - size.y / 2;
    msg_p = (sfVector2i){(o.x + 1) * 8, (o.y + 1) * 8};
    frame_draw(self, screen, o, size);
    gui_text_draw("Oh no your ded ! :(", screen, msg_p, sfWhite);
    print_entries(screen, select, o);
}