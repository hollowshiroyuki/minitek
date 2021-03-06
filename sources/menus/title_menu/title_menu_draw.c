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
#include "consts.h"

const char *title_menu_entries[] = {
    "Play",
    "Options",
    "About",
    "Quit"
};

static void print_title(sfVector2i size, screen_t *screen)
{
    sfVector2i pos;
    sfVector2i off = (sfVector2i){(screen->size.x - size.x * 8) / 2, 24};

    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            pos = (sfVector2i){off.x + x * 8, off.y + y * 8};
            screen_render_gui(screen, pos, x + y * 32, 0);
        }
    }
}

static void print_entries(sfVector2i size, screen_t *screen, int selection)
{
    char entry[20] = {0};
    sfColor color = sfWhite;
    sfVector2i pos;

    for (int i = 0; i < 4; i++) {
        color = sfWhite;
        if (i == selection) {
            hsy_strcat(entry, "> ");
            hsy_strcat(entry, title_menu_entries[i]);
            hsy_strcat(entry, "  ");
            color = sfYellow;
        } else
            hsy_strcat(entry, title_menu_entries[i]);
        pos.x = (screen->size.x - hsy_strlen(entry) * 8) / 2;
        pos.y = (8 + i) * 8;
        gui_text_draw(entry, screen, pos, color);
        entry[0] = '\0';
    }
}

void title_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i size = (sfVector2i){13, 2};
    sfVector2f s = (sfVector2f){map_size.x, map_size.y};
    sfVector2f scale = (sfVector2f){screen->size.x / s.x, screen->size.y / s.y};

    sfSprite_setScale(self->title.background, scale);
    sfRenderWindow_drawSprite(screen->win, self->title.background, NULL);
    print_title(size, screen);
    gui_frame_draw(screen, "", (sfVector2i){11, 7}, (sfVector2i){22, 12});
    print_entries(size, screen, self->title.selection);
    if (self->child)
        (self->child->funcs.draw)(self->child, screen);
}