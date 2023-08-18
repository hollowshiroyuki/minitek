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
#include "gui.h"

void text_particle_draw(entity_t *self, screen_t *scr)
{
    sfVector2i pos = (sfVector2i){self->pos.x, 0};

    pos.y = self->pos.y - self->tpart.b.z + 1;
    gui_num_draw(self->tpart.msg, scr, pos, sfBlack);
    pos.y = self->pos.y - self->tpart.b.z;
    gui_num_draw(self->tpart.msg, scr, pos, self->tpart.color);
}