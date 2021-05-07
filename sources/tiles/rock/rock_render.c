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
    int t = T_ROCK;

    c->u = floor_get_tile(floor, (sfVector2i){pos.x, pos.y - 1}).id != T_ROCK;
    c->d = floor_get_tile(floor, (sfVector2i){pos.x, pos.y + 1}).id != T_ROCK;
    c->l = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y}).id != T_ROCK;
    c->r = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y}).id != T_ROCK;
    c->ul = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y - 1}).id != t;
    c->dl = floor_get_tile(floor, (sfVector2i){pos.x - 1, pos.y + 1}).id != t;
    c->ur = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y - 1}).id != t;
    c->dr = floor_get_tile(floor, (sfVector2i){pos.x + 1, pos.y + 1}).id != t;
}

static void top(connec_t *c, screen_t *scr, sfVector2i pos, int tex[13])
{
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16};
    int o = tex[0];
    int to = (c->l ? 2 : 1) + (c->u ? 2 : 1) * 32;

    if (!c->u && !c->l) {
        if (!c->ul)
            screen_render_tile(scr, p_off, tex[9], 0);
        else
            screen_render_tile(scr, p_off, tex[13], 3);
    } else
        screen_render_tile(scr, p_off, o + to, 3);
    to = (c->r ? 0 : 1) + (c->u ? 2 : 1) * 32;
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16};
    if (!c->u && !c->r) {
        if (!c->ur)
            screen_render_tile(scr, p_off, tex[10], 0);
        else
            screen_render_tile(scr, p_off, tex[14], 3);
    } else
        screen_render_tile(scr, p_off, o + to, 3);
}

static void bottom(connec_t *c, screen_t *scr, sfVector2i pos, int tex[13])
{
    sfVector2i p_off = (sfVector2i){pos.x * 16, pos.y * 16 + 8};
    int o = tex[0];
    int to = (c->l ? 2 : 1) + (c->d ? 0 : 1) * 32;

    if (!c->d && !c->l) {
        if (!c->dl)
            screen_render_tile(scr, p_off, tex[11], 0);
        else
            screen_render_tile(scr, p_off, tex[15], 3);
    } else
        screen_render_tile(scr, p_off, o + to, 3);
    to = (c->r ? 0 : 1) + (c->d ? 0 : 1) * 32;
    p_off = (sfVector2i){pos.x * 16 + 8, pos.y * 16 + 8};
    if (!c->d && !c->r) {
        if (!c->dr)
            screen_render_tile(scr, p_off, tex[12], 0);
        else
            screen_render_tile(scr, p_off, tex[16], 3);
    } else
        screen_render_tile(scr, p_off, o + to, 3);
}

void rock_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    connec_t connec;
    int o = 6 * 32 + 18;
    int tex[17] = {o, o + 1, o + 2, 0, 0, 0, 0, 0, 0, o + 3, o + 4};

    for (int i = 1; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tex[i * 3 + j] = tex[(i - 1 * 3 + j)] + 32;
    for (int i = 1; i < 4; i++)
        for (int j = 0; j < 2; j++)
            tex[9 + i * 2 + j] = tex[9 + (i - 1) * 2 + j] + 32;
    get_connections(&connec, floor, pos);
    dirt_render(self, scr, floor, pos);
    top(&connec, scr, pos, tex);
    bottom(&connec, scr, pos, tex);
}