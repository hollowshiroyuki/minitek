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
#include "tiles/dirt.h"

void stair_down_render(tile_t self, screen_t *scr, floor_t *flr, sfVector2i p)
{
    dirt_render(self, scr, flr, p);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, 21, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, 22, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, 53, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, 52, 0);
}