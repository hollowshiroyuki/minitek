/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "screen.h"
#include <stdio.h>
#include "entities_id.h"

void item_entity_draw(entity_t *self, screen_t *screen)
{
    int tex = (self->itm.item->funcs.get_tex)(self->itm.item);
    int io = (int)self->itm.b.z;
    sfVector2i s_pos = (sfVector2i){self->pos.x - 4, self->pos.y - 4};
    sfVector2i i_pos = (sfVector2i){self->pos.x - 4, self->pos.y - 4 - io};

    if (self->itm.time >= self->itm.lifetime - 6 * 20)
        if (self->itm.time / 6 % 2 == 0)
            return;
    sfSprite_setColor(screen->i_sprite, sfBlack);
    screen_render_item(screen, s_pos, tex, 0);
    sfSprite_setColor(screen->i_sprite, sfWhite);
    screen_render_item(screen, i_pos, tex, 0);
}