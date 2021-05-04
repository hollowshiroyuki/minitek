/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "screen.h"
#include "floor.h"
#include <stdio.h>

void draw_active_item(universe_t *self, screen_t *screen)
{
    item_t *active_item = self->player->mob.pla.active_item;
    sfVector2i size = screen->size;
    sfVector2i pos = {size.x - 12 * 8, size.y - 2 * 8};

    if (active_item)
        (active_item->funcs.draw_inventory)(active_item, screen, pos);
}

void draw_health(mob_t *mob, screen_t *scr)
{
    sfVector2i size = scr->size;
    sfVector2i p = (sfVector2i){1 * 8, size.y - 3 * 8};
    int first = (mob->health) ? 2 : 3;

    screen_render_gui(scr, (sfVector2i){p.x - 1, p.y}, 32 * first, HOR_F);
    for (int i = 0; i < mob->max_health; i++) {
        if (i < mob->health)
            screen_render_gui(scr, (sfVector2i){p.x + i * 8, p.y}, 32 * 2, 0);
        else
            screen_render_gui(scr, (sfVector2i){p.x + i * 8, p.y}, 32 * 3, 0);
    }
}

void draw_stamina(player_t *pla, screen_t *scr)
{
    sfVector2i pos = (sfVector2i){1 * 8, scr->size.y - 2 * 8};

    for (int i = 0; i < pla->max_stamina; i++) {
        if (pla->stamina_delay > 0) {
            if (pla->stamina_delay / 4 % 2 == 0) {
                screen_render_gui(scr, pos, 32 * 3 + 1, 0);
            } else {
                screen_render_gui(scr, pos, 32 * 4 + 1, 0);
            }
        } else {
            if (i < pla->stamina) {
                screen_render_gui(scr, pos, 32 * 2 + 1, 0);
            } else {
                screen_render_gui(scr, pos, 32 * 3 + 1, 0);
            }
        }
        pos.x += 1 * 8;
    }
}

void universe_draw_gui(universe_t *self, screen_t *screen)
{
    draw_health(&self->player->mob, screen);
    draw_stamina(&self->player->mob.pla, screen);
    draw_active_item(self, screen);
    if (self->menu)
        (*self->menu->funcs.draw)(self->menu, screen);
}