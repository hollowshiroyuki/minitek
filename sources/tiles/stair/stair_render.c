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

void stair_render(tile_t self, screen_t *scr, floor_t *flr, sfVector2i p)
{
    int tex = (self.variant == 1) ? 19 : 21;
    int tex2 = (self.variant == 1) ?  52 : 54;

    dirt_render(self, scr, flr, p);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16}, tex, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16}, tex + 1, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16, p.y * 16 + 8}, tex2 - 1, 0);
    screen_render_tile(scr, (sfVector2i){p.x * 16 + 8, p.y * 16 + 8}, tex2, 0);
}