/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "screen.h"
#include <stdio.h>

void floor_draw_background(floor_t *self, sfVector2i scroll, screen_t *screen)
{
    sfVector2i o = {scroll.x >> 4, scroll.y >> 4};
    sfVector2i size = {(screen->size.x + 15) >> 4, (screen->size.y + 15) >> 4};
    sfVector2i pos = {0};
    tile_t tile = {0};

    screen_set_offset(screen, scroll);
    for (int y = o.y; y <= size.y + o.y; y++) {
        for (int x = o.x; x <= size.x + o.x; x++) {
            pos = (sfVector2i){x, y};
            tile = floor_get_tile(self, pos);
            if (tile.render) {
                (*tile.render)(tile, screen, self, pos);
            }
        }
    }
}