/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "tiles/tile.h"
#include "tiles_id.h"
#include "index_til.h"
#include "floor.h"
#include "screen.h"
#include "random.h"
#include "tiles/dirt.h"

static void get_connections(bool c[4], floor_t *floor, sfVector2i pos)
{
    c[0] = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).sand;
    c[1] = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).sand;
    c[2] = !floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).sand;
    c[3] = !floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).sand;
}

static void top_left(bool c[4], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16;
    pos.y = pos.y * 16;
    if (!c[0] && !c[2]) {
        screen_render_tile(scr, pos, 32 * 6 + 9, 0);
    } else {
        tex = (c[2] ? 6 * 32 + 6 : 6 * 32 + 7) + (c[0] ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex, 0);
    }
}

static void top_right(bool c[4], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16 + 8;
    pos.y = pos.y * 16;
    if (!c[0] && !c[3]) {
        screen_render_tile(scr, pos, 32 * 6 + 10, 0);
    } else {
        tex = (c[3] ? 6 * 32 + 8 : 6 * 32 + 7) + (c[0] ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex, 0);
    }
}

static void bottom_left(bool c[4], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16;
    pos.y = pos.y * 16 + 8;
    if (!c[1] && !c[2]) {
        screen_render_tile(scr, pos, 32 * 7 + 9, 0);
    } else {
        tex = (c[2] ? 6 * 32 + 6 : 6 * 32 + 7) + (c[1] ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex, 0);
    }
}

static void bottom_right(bool c[4], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16 + 8;
    pos.y = pos.y * 16 + 8;
    if (!c[1] && !c[3]) {
        screen_render_tile(scr, pos, 32 * 7 + 10, 0);
    } else {
        tex = (c[3] ? 6 * 32 + 8 : 6 * 32 + 7) + (c[1] ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex, 0);
    }
}

void sand_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    bool c[4] = {0};
    int v[4] = {2, 3, 4, 5};

    get_connections(c, floor, pos);
    dirt_render(self, scr, floor, pos);
    top_left(c, scr, pos, v);
    top_right(c, scr, pos, v);
    bottom_left(c, scr, pos, v);
    bottom_right(c, scr, pos, v);
}