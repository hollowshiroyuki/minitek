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
    sfVector2i pos = self->pos;

    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y - 4}, 0, 0);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y - 4}, 1, 0);
    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y + 4}, 32, 0);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y + 4}, 33, 0);
}