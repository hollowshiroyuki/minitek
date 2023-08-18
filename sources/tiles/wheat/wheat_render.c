/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"

#include "floor.h"
#include "screen.h"
#include "tiles/farmland.h"

void wheat_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p)
{
    int data = floor_get_data(floor, p);
    int tex = data / 10 + 13;

    farmland_render(self, scr, floor, p);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, tex, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, tex, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, tex, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, tex, 0);
}