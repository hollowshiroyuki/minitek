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
    sfVector2i pos = self->pos;
    int tex = (self->fur.tex * 2 + 8 + (26 * 32));

    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y - 4}, tex);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y - 4}, tex + 1);
    screen_render_entity(screen, (sfVector2i){pos.x - 8, pos.y + 4}, tex + 32);
    screen_render_entity(screen, (sfVector2i){pos.x, pos.y + 4}, tex + 33);
}