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

void dirt_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p)
{
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, 76, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, 77, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, 109, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, 108, 0);
}