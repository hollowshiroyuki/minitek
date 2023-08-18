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

void ore_render(tile_t self, screen_t *scr, floor_t *floor, sfVector2i p)
{
    int ul = 24 + self.variant;
    int ur = ul + 1;
    int dl = ul + 32;
    int dr = dl + 1;

    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, ul, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, ur, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, dl, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, dr, 0);
}