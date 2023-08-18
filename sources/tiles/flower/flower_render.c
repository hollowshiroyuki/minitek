/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "index_til.h"
#include "floor.h"
#include "screen.h"
#include "tiles/grass.h"
#include "tiles/dirt.h"

void flower_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p)
{
    int data = floor_get_data(floor, p);
    int shape = (data / 16) % 2;
    int tex = 8 * 32 + 3;
    sfVector2i l_pos = (sfVector2i){p.x * 16 + 8, p.y * 16 + 8};

    grass_render(self, scr, floor, p);
    if (shape == 0)
        screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, tex, 0);
    if (shape == 1)
        screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, tex, 0);
    if (shape == 2)
        screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, tex, 0);
    if (shape == 3)
        screen_render_tile(scr, l_pos, tex, 0);
}