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

static void get_connections(bool c[8], floor_t *floor, sfVector2i pos)
{
    c[0] = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).water;
    c[1] = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).water;
    c[2] = !floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).water;
    c[3] = !floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).water;
    c[4] = c[0] && floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).sand;
    c[5] = c[1] && floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).sand;
    c[6] = c[2] && floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).sand;
    c[7] = c[3] && floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).sand;
}

static void top_left(bool c[8], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16;
    pos.y = pos.y * 16;
    if (!c[0] && !c[2]) {
        screen_render_tile(scr, pos, v[random_int(4)]);
    } else {
        tex = (c[2] ? 6 * 32 + 12 : 6 * 32 + 13) + (c[0] ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex);
    }
}

static void top_right(bool c[8], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16 + 8;
    pos.y = pos.y * 16;
    if (!c[0] && !c[3]) {
        screen_render_tile(scr, pos, v[random_int(4)]);
    } else {
        tex = (c[3] ? 6 * 32 + 14 : 6 * 32 + 13) + (c[0] ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex);
    }
}

static void bottom_left(bool c[8], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16;
    pos.y = pos.y * 16 + 8;
    if (!c[1] && !c[2]) {
        screen_render_tile(scr, pos, v[random_int(4)]);
    } else {
        tex = (c[2] ? 6 * 32 + 12 : 6 * 32 + 13) + (c[1] ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex);
    }
}

static void bottom_right(bool c[8], screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;

    pos.x = pos.x * 16 + 8;
    pos.y = pos.y * 16 + 8;
    if (!c[1] && !c[3]) {
        screen_render_tile(scr, pos, v[random_int(4)]);
    } else {
        tex = (c[3] ? 6 * 32 + 14 : 6 * 32 + 13) + (c[1] ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex);
    }
}

void water_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    bool c[8] = {0};
    int v[4] = {2, 3, 4, 5};

    get_connections(c, floor, pos);
    dirt_render(self, scr, floor, pos);
    top_left(c, scr, pos, v);
    top_right(c, scr, pos, v);
    bottom_left(c, scr, pos, v);
    bottom_right(c, scr, pos, v);
}