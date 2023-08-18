/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "screen.h"
#include <stdio.h>

void screen_render_tile(screen_t *self, sfVector2i pos, int tile_id)
{
    sfVector2i tile = {(tile_id % 32) * 8, (tile_id / 32) * 8};
    sfIntRect rect = {tile.x, tile.y, 8, 8};

    pos.x -= self->offset.x;
    pos.y -= self->offset.y;
    if (pos.x < 0 || pos.x >= self->size.x)
        return;
    if (pos.y < 0 || pos.y >= self->size.y)
        return;
    sfSprite_setTextureRect(self->t_sprite, rect);
    sfSprite_setPosition(self->t_sprite, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawSprite(self->win, self->t_sprite, NULL);
}