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
#include "tiles/sand.h"

void cactus_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p)
{
    sand_render(self, scr, floor, p);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, 6, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, 7, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, 38, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, 39, 0);
}