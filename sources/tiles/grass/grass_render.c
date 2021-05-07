/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "tiles/tile.h"
#include "tiles_id.h"
#include "floor.h"
#include "screen.h"
#include "random.h"
#include "tiles/dirt.h"

static void get_connections(connec_t *c, floor_t *floor, sfVector2i pos)
{
    c->u = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).grass;
    c->d = !floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).grass;
    c->l = !floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).grass;
    c->r = !floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).grass;
}

static void top(connec_t *c, screen_t *scr, sfVector2i pos)
{
    int tex = 0;

    pos = (sfVector2i){pos.x * 16, pos.y * 16};
    if (!c->u && !c->l) {
        screen_render_tile(scr, pos, 6 * 32 + 3, 0);
    } else {
        tex = (c->l ? 6 * 32 + 0 : 6 * 32 + 1) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex, 0);
    }
    pos.x += 8;
    if (!c->u && !c->r) {
        screen_render_tile(scr, pos, 6 * 32 + 4, 0);
    } else {
        tex = (c->r ? 6 * 32 + 2 : 6 * 32 + 1) + (c->u ? 0 : 1) * 32;
        screen_render_tile(scr, pos, tex, 0);
    }
}

static void bottom(connec_t *c, screen_t *scr, sfVector2i pos)
{
    int tex = 0;

    pos = (sfVector2i){pos.x * 16, pos.y * 16 + 8};
    if (!c->d && !c->l) {
        screen_render_tile(scr, pos, 7 * 32 + 3, 0);
    } else {
        tex = (c->l ? 6 * 32 + 0 : 6 * 32 + 1) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex, 0);
    }
    pos.x += 8;
    if (!c->d && !c->r) {
        screen_render_tile(scr, pos, 6 * 32 + 4, 0);
    } else {
        tex = (c->r ? 6 * 32 + 2 : 6 * 32 + 1) + (c->d ? 2 : 1) * 32;
        screen_render_tile(scr, (sfVector2i){pos.x, pos.y}, tex, 0);
    }
}

void grass_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    connec_t c;

    get_connections(&c, floor, pos);
    dirt_render(self, scr, floor, pos);
    top(&c, scr, pos);
    bottom(&c, scr, pos);
}