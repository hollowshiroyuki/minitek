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

static void get_connections(connec_t *c, floor_t *floor, sfVector2i pos)
{
    c->u = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).water;
    c->d = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).water;
    c->l = !floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).water;
    c->r = !floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).water;
    c->su = c->u && floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).sand;
    c->sd = c->d && floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).sand;
    c->sl = c->l && floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).sand;
    c->sr = c->r && floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).sand;
}

static void top(connec_t *c, screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16};

    if (!c->u && !c->l) {
        screen_render_tile(scr, p_off, v[0], 0);
    } else {
        tex = (c->l ? 6 * 32 + 12 : 6 * 32 + 13) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16};
    if (!c->u && !c->r) {
        screen_render_tile(scr, p_off, v[1], 0);
    } else {
        tex = (c->r ? 6 * 32 + 14 : 6 * 32 + 13) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
}

static void bottom(connec_t *c, screen_t *scr, sfVector2i pos, int v[4])
{
    int tex = 0;
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16 + 8};

    if (!c->d && !c->l) {
        screen_render_tile(scr, p_off, v[2], 0);
    } else {
        tex = (c->l ? 6 * 32 + 12 : 6 * 32 + 13) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16 + 8};
    if (!c->d && !c->r) {
        screen_render_tile(scr, p_off, v[3], 0);
    } else {
        tex = (c->r ? 6 * 32 + 14 : 6 * 32 + 13) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
}

void water_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    connec_t connec;
    int v[4] = {0};
    int seed = (floor->tickCount + (pos.x / 2 - pos.y) * 4242) / 10 * 69696969;

    srand(seed);
    v[0] = 2 + random_int(4);
    v[1] = 2 + random_int(4);
    v[2] = 2 + random_int(4);
    v[3] = 2 + random_int(4);
    get_connections(&connec, floor, pos);
    dirt_render(self, scr, floor, pos);
    top(&connec, scr, pos, v);
    bottom(&connec, scr, pos, v);
}