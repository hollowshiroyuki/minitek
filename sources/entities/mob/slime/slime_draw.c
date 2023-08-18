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

void slime_draw(entity_t *self, screen_t *screen)
{
    int t = self->mob.sli.level * 32;
    sfVector2i o = (sfVector2i){self->pos.x - 8, self->pos.y - 11};

    if (self->mob.sli.jump_time > 0) {
        t += 2;
        o.y -= 4;
    }
    if (self->mob.hurt_time > 0)
        sfSprite_setColor(screen->e_sprite, sfRed);
    screen_render_entity(screen, o, t, 0);
    screen_render_entity(screen, (sfVector2i){o.x + 8, o.y}, t + 1, 0);
    screen_render_entity(screen, (sfVector2i){o.x, o.y + 8}, t + 32, 0);
    screen_render_entity(screen, (sfVector2i){o.x + 8, o.y + 8}, t + 33, 0);
    sfSprite_setColor(screen->e_sprite, sfWhite);
}