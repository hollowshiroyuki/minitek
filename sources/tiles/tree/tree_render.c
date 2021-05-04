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
#include "tiles/grass.h"

static void get_connections(connec_t *c, floor_t *floor, sfVector2i pos)
{
    int t = T_TREE;

    c->u = floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).id == T_TREE;
    c->d = floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).id == T_TREE;
    c->l = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).id == T_TREE;
    c->r = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).id == T_TREE;
    c->ul = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y - 1}).id == t;
    c->dl = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y + 1}).id == t;
    c->ur = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y - 1}).id == t;
    c->dr = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y + 1}).id == t;
}

static void top(connec_t *c, screen_t *scr, sfVector2i pos)
{
    if (c->u && c->ul && c->l)
        screen_render_tile(scr, pos, 32 * 1 + 1, 0);
    else
        screen_render_tile(scr, pos, 0, 0);
    pos.x += 8;
    if (c->u && c->ur && c->r)
        screen_render_tile(scr, pos, 32 * 2 + 1, 0);
    else
        screen_render_tile(scr, pos, 1, 0);
}

static void bottom(connec_t *c, screen_t *scr, sfVector2i pos)
{
    pos.y += 8;
    if (c->d && c->dl && c->l)
        screen_render_tile(scr, pos, 32 * 2 + 1, 0);
    else
        screen_render_tile(scr, pos, 32, 0);
    pos.x += 8;
    if (c->d && c->dr && c->r)
        screen_render_tile(scr, pos, 33, 0);
    else
        screen_render_tile(scr, pos, 3 * 32 + 1, 0);
}

void tree_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    connec_t connec;
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16};

    get_connections(&connec, floor, pos);
    grass_render(self, scr, floor, pos);
    top(&connec, scr, p_off);
    bottom(&connec, scr, p_off);
}