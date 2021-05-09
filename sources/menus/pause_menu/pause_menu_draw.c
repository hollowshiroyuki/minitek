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

const char *pause_menu_entries[] = {
    "Continue",
    "Save",
    "Main Menu",
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

    for (int i = 0; i < 4; i++) {
        color = sfWhite;
        if (i == selection) {
            hsy_strcat(entry, "> ");
            hsy_strcat(entry, pause_menu_entries[i]);
            hsy_strcat(entry, "  ");
            color = sfYellow;
        } else
            hsy_strcat(entry, pause_menu_entries[i]);
        pos.x = ((o.x * (5 * 8)) - hsy_strlen(entry) * 8) / 2;
        pos.y = (o.y + 4 + i) * 8;
        gui_text_draw(entry, screen, pos, color);
        entry[0] = '\0';
    }
}

void draw_save(screen_t *scr)
{
    sfVector2i pos1 = (sfVector2i){1, 1};
    sfVector2i pos2 = (sfVector2i){15, 3};

    gui_frame_draw(scr, "", pos1, pos2);
    pos1 = (sfVector2i){(pos1.x + 1) * 8, (pos1.y + 1) * 8};
    gui_text_draw("Saving...", scr, pos1, sfYellow);
}

void pause_menu_draw(menu_t *self, screen_t *screen)
{
    int select = self->dea.selection;
    sfVector2i size = (sfVector2i){20, 8};
    sfVector2i o = (sfVector2i){screen->size.x / 8 / 2 - size.x / 2, 0};
    sfVector2i msg_p;

    o.y = (screen->size.y / 8) / 2 - size.y / 2;
    msg_p = (sfVector2i){(o.x + 6) * 8, (o.y + 1) * 8};
    frame_draw(self, screen, o, size);
    gui_text_draw("@ Pause @", screen, msg_p, sfWhite);
    print_entries(screen, select, o);
    if (self->pause.will_save) {
        draw_save(screen);
    }
}