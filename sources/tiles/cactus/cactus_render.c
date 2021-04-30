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
#include "tiles/sand.h"

void cactus_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    sand_render(self, scr, floor, pos);
    screen_render_tile(scr, (sfVector2i){pos.x * 16, pos.y * 16}, 6);
    screen_render_tile(scr, (sfVector2i){pos.x * 16 + 8, pos.y * 16}, 7);
    screen_render_tile(scr, (sfVector2i){pos.x * 16, pos.y * 16 + 8}, 38);
    screen_render_tile(scr, (sfVector2i){pos.x * 16 + 8, pos.y * 16 + 8}, 39);
}