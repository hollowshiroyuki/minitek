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

const char *about_menu_text[] = {
    "This is a just a PoC",
    "You can break trees, rocks",
    "Collect items and craft stuff,",
    "dig holes with a shovel",
    "and kill some monsters too.",
    "The game support saving and",
    "loading maps.",
    "",
    "It was planned to have way",
    "more interactions and items",
    "but i didn't have the time",
    "to add everything.",
    "",
    "The engine is extensible",
    "with enough time.",
    "",
    "",
    "(C) HSY, ETIPEK 2021",
    0
};

void about_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i size = (sfVector2i){13, 2};
    sfVector2i s = (sfVector2i){screen->size.x, screen->size.y};
    sfVector2i pos2 = (sfVector2i){s.x / 8 - 2, s.y / 8 - 2};
    sfVector2i pos = (sfVector2i){3 * 8, 3 * 8};

    gui_frame_draw(screen, "", (sfVector2i){2, 2}, pos2);
    for (int i = 0; about_menu_text[i]; i++) {
        gui_text_draw((char *)about_menu_text[i], screen, pos, sfWhite);
        pos.y += 8;
    }
}