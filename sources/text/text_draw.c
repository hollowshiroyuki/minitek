/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "screen.h"
#include "hsy.h"

const char *chars = "" \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345" \
    "6789.,!?'\"-+=/\\%()<>:;^@?"
;

static int get_index(char c)
{
    for (int i = 0; chars[i]; i++)
        if (chars[i] == c)
            return (i);
    return (-1);
}

void text_draw(char *text, screen_t *screen, sfVector2i pos, sfColor color)
{
    char *msg = hsy_strdup(text);
    sfVector2i cpos;
    int tex;

    hsy_strupcase(msg);
    sfSprite_setColor(screen->g_sprite, color);
    for (int i = 0; msg[i]; i++) {
        tex = get_index(msg[i]);
        cpos = (sfVector2i){pos.x + i * 8, pos.y};
        if (tex == -1)
            continue;
        screen_render_gui(screen, cpos, tex + 28 * 32);
    }
    sfSprite_setColor(screen->g_sprite, sfWhite);
    free(msg);
}