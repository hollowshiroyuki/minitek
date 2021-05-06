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

void furniture_draw(entity_t *self, screen_t *screen)
{
    sfVector2i p = self->pos;
    int t = (self->fur.tex * 2 + 8 + (26 * 32));

    screen_render_entity(screen, (sfVector2i){p.x - 8, p.y - 4}, t, 0);
    screen_render_entity(screen, (sfVector2i){p.x, p.y - 4}, t + 1, 0);
    screen_render_entity(screen, (sfVector2i){p.x - 8, p.y + 4}, t + 32, 0);
    screen_render_entity(screen, (sfVector2i){p.x, p.y + 4}, t + 33, 0);
}