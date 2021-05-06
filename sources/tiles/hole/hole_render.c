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

static bool liquids(tile_t tile)
{
    return (tile.lava || tile.water);
}

static void get_connections(connec_t *c, floor_t *floor, sfVector2i pos)
{
    c->u = !liquids(floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}));
    c->d = !liquids(floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}));
    c->l = !liquids(floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}));
    c->r = !liquids(floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}));
    c->su = c->u && floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).sand;
    c->sd = c->d && floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).sand;
    c->sl = c->l && floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).sand;
    c->sr = c->r && floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).sand;
}

static void top(connec_t *c, screen_t *scr, sfVector2i pos)
{
    int tex = 0;
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16};

    if (!c->u && !c->l) {
        screen_render_tile(scr, p_off, 27 + 32 * 6, 0);
    } else {
        tex = (c->l ? 24 + 32 * 6 : 25 + 32 * 6) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16};
    if (!c->u && !c->r) {
        screen_render_tile(scr, p_off, 28 + 32 * 6, 0);
    } else {
        tex = (c->r ? 26 + 32 * 6 : 25 + 32 * 6) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
}

static void bottom(connec_t *c, screen_t *scr, sfVector2i pos)
{
    int tex = 0;
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16 + 8};

    if (!c->d && !c->l) {
        screen_render_tile(scr, p_off, 27 + 32 * 7, 0);
    } else {
        tex = (c->l ? 24 + 32 * 6 : 25 + 32 * 6) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16 + 8};
    if (!c->d && !c->r) {
        screen_render_tile(scr, p_off, 28 + 32 * 7, 0);
    } else {
        tex = (c->r ? 26 + 32 * 6 : 25 + 32 * 6) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, p_off, tex, 0);
    }
}

void hole_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    connec_t c;

    get_connections(&c, floor, pos);
    dirt_render(self, scr, floor, pos);
    top(&c, scr, pos);
    bottom(&c, scr, pos);
}