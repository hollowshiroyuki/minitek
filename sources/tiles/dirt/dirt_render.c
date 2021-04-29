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

void dirt_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i pos)
{
    screen_render_tile(scr, (sfVector2i){pos.x * 16, pos.y * 16}, 76);
    screen_render_tile(scr, (sfVector2i){pos.x * 16 + 8, pos.y * 16}, 77);
    screen_render_tile(scr, (sfVector2i){pos.x * 16, pos.y * 16 + 8}, 109);
    screen_render_tile(scr, (sfVector2i){pos.x * 16 + 8, pos.y * 16 + 8}, 108);
}