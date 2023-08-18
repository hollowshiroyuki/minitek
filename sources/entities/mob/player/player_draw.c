/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/player.h"
#include <stdio.h>
#include "screen.h"

void player_draw(entity_t *self, screen_t *screen)
{
    sfVector2i pos = self->pos;

    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y - 4}, 512);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y - 4}, 513);
    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y + 4}, 544);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y + 4}, 545);
}