/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/slime.h"
#include "screen.h"
#include <stdio.h>
#include "entities_id.h"

void zombie_draw(entity_t *self, screen_t *scr)
{
    int t = 8 +(self->mob.zom.level * 32);
    sfVector2i o = (sfVector2i){self->pos.x - 8, self->pos.y - 11};
    sfVector2i f = (sfVector2i){(self->mob.walk_dist >> 3) & 1, f.x};

    t += (self->mob.dir == 1) ? 2 : 0;
    if (self->mob.dir > 1) {
        f.x = (self->mob.dir == 2) ? 1 : 0;
        f.y = (self->mob.walk_dist >> 4) & 1;
        t += 4 + ((self->mob.walk_dist >> 3) & 1) * 2;
    }
    if (self->mob.hurt_time > 0)
        sfSprite_setColor(scr->e_sprite, sfRed);
    screen_render_entity(scr, (sfVector2i){o.x + 8 * f.x, o.y}, t, f.x);
    screen_render_entity(scr, (sfVector2i){o.x + 8 - 8 * f.x, o.y}, t + 1, f.x);
    o.y += 8;
    t += 32;
    screen_render_entity(scr, (sfVector2i){o.x + 8 * f.y, o.y}, t, f.y);
    screen_render_entity(scr, (sfVector2i){o.x + 8 - 8 * f.y, o.y}, ++t, f.y);
    sfSprite_setColor(scr->e_sprite, sfWhite);
}