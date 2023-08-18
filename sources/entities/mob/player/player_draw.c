/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/player.h"
#include "tiles_id.h"
#include <stdio.h>
#include "screen.h"
#include "items_id.h"

static void swim(entity_t *self, screen_t *screen, sfVector2i *off)
{
    sfVector2i tile_pos = (sfVector2i){self->pos.x >> 4, self->pos.y >> 4};
    tile_t tile = floor_get_tile(self->floor, tile_pos);
    sfVector2i pos = (sfVector2i){off->x, off->y + 3};
    int tex = (tile.id == T_WATER) ? (32 * 2 + 5) : (32 * 2 + 6);

    if ((mob_is_swimming(self))) {
        if (self->mob.tick_time / 8 % 4 == 0) {
            sfSprite_setColor(screen->g_sprite, sfBlack);
        }
        screen_render_gui(screen, pos, tex, 0);
        pos.x += 8;
        screen_render_gui(screen, pos, tex, HOR_F);
        sfSprite_setColor(screen->g_sprite, sfWhite);
    }
}

static void draw_slash(entity_t *self, screen_t *screen, sfVector2i p)
{
    item_t *ai = self->mob.pla.active_item;

    if (self->mob.pla.attack_time > 0 && self->mob.dir == 2) {
        screen_render_gui(screen, (sfVector2i){p.x - 4, p.y}, 68, 1);
        screen_render_gui(screen, (sfVector2i){p.x - 4, p.y + 8}, 68, 3);
        if (ai)
            (*ai->funcs.draw_icon)(ai, screen, (sfVector2i){p.x - 4, p.y + 4});
    }
    if (self->mob.pla.attack_time > 0 && self->mob.dir == 3) {
        screen_render_gui(screen, (sfVector2i){p.x + 12, p.y}, 68, 0);
        screen_render_gui(screen, (sfVector2i){p.x + 12, p.y + 8}, 68, 2);
        if (ai)
            (*ai->funcs.draw_icon)(ai, screen, (sfVector2i){p.x + 12, p.y + 4});
    }
    if (self->mob.pla.attack_time > 0 && self->mob.dir == 0) {
        screen_render_gui(screen, (sfVector2i){p.x, p.y + 12}, 67, 2);
        screen_render_gui(screen, (sfVector2i){p.x + 8, p.y + 12}, 67, 3);
        if (ai)
            (*ai->funcs.draw_icon)(ai, screen, (sfVector2i){p.x + 4, p.y + 12});
    }
}

static void draw_top(entity_t *self, screen_t *screen, sfVector2i p, int *t)
{
    item_t *ai = self->mob.pla.active_item;

    if (self->mob.pla.attack_time > 0 && self->mob.dir == 1) {
        screen_render_gui(screen, (sfVector2i){p.x, p.y - 4}, 67, 0);
        screen_render_gui(screen, (sfVector2i){p.x + 8, p.y - 4}, 67, 1);
        if (ai)
            (*ai->funcs.draw_icon)(ai, screen, (sfVector2i){p.x + 4, p.y - 4});
    }
    if (self->mob.hurt_time > 0)
        sfSprite_setColor(screen->e_sprite, sfRed);
    if (ai && ai->id == I_FURNITURE)
        *t += 2 * 32;
}

static void draw_player(entity_t *sl, screen_t *s, sfVector2i po, sfVector3f f)
{
    int t = f.z;
    item_t * ai = sl->mob.pla.active_item;
    sfVector2i p = (sfVector2i){po.x + 8 * f.y, po.y + 8};

    screen_render_entity(s, (sfVector2i){po.x + 8 * f.x, po.y}, t, f.x);
    screen_render_entity(s, (sfVector2i){po.x + 8 - 8 * f.x, po.y}, t + 1, f.x);
    t += 32;
    if (!mob_is_swimming(sl)) {
        screen_render_entity(s, p, t, f.y);
        p = (sfVector2i){po.x + 8 - 8 * f.y, po.y + 8};
        screen_render_entity(s, p, t + 1, f.y);
    }
    sfSprite_setColor(s->e_sprite, sfWhite);
    if (ai && ai->id == I_FURNITURE) {
        ai->fur.furniture->pos = (sfVector2i){sl->pos.x, po.y - 8};
        (ai->fur.furniture->funcs.draw)(ai->fur.furniture, s);
    }
}

void player_draw(entity_t *self, screen_t *screen)
{
    sfVector2i p = self->pos;
    sfVector2i f = {(self->mob.walk_dist >> 3) & 1, f.x};
    int t = 16 * 32;
    sfVector2i po = (sfVector2i){self->pos.x - 8, self->pos.y - 11};

    if (self->mob.dir == 1)
        t += 2;
    if (self->mob.dir > 1) {
        f.x = (self->mob.dir == 2) ? 1 : 0;
        f.y = (self->mob.walk_dist >> 4) & 1;
        t += 4 + ((self->mob.walk_dist >> 3) & 1) * 2;
    }
    swim(self, screen, &po);
    draw_top(self, screen, po, &t);
    draw_slash(self, screen, po);
    draw_player(self, screen, po, (sfVector3f){f.x, f.y, t});
}