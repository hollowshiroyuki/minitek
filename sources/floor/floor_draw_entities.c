/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include "floor.h"
#include "screen.h"
#include <stdio.h>
#include "entities/entity.h"

void floor_draw_entities(floor_t *self, sfVector2i scroll, screen_t *screen)
{
    sfVector2i o = {scroll.x >> 4, scroll.y >> 4};
    sfVector2i size = {(screen->size.x + 15) >> 4, (screen->size.y + 15) >> 4};
    sfVector2i pos = {0};
    entity_t **in_tile;

    screen_set_offset(screen, scroll);
    for (int y = o.y; y <= size.y + o.y; y++) {
        for (int x = o.x; x <= size.x + o.x; x++) {
            if (x < 0 || y < 0 || x >= self->size.x || y >= self->size.y)
                continue;
            in_tile = self->entities_in_tiles[x + y * self->size.x];
            entities_add_all(self->entities_row, in_tile);
            if (self->entities_row[0]) {
                floor_sort_and_draw(self, screen, self->entities_row);
            }
            floor_entities_row_clear(self->entities_row, self->size.x);
        }
    }
    screen_set_offset(screen, (sfVector2i){0, 0});
}