/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "screen.h"
#include <stdio.h>

void screen_render_tile(screen_t *self, sfVector2i pos, int tile_id, int flip)
{
    sfVector2i tile = {(tile_id % 32) * 8, (tile_id / 32) * 8};
    sfIntRect rect = {tile.x, tile.y, 8, 8};

    pos.x -= self->offset.x;
    pos.y -= self->offset.y;
    if (pos.x < -8 || pos.x >= self->size.x + 8)
        return;
    if (pos.y < -8 || pos.y >= self->size.y + 8)
        return;
    sfSprite_setTextureRect(self->t_sprite, rect);
    screen_sprite_flip(self->t_sprite, flip);
    sfSprite_setPosition(self->t_sprite, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawSprite(self->win, self->t_sprite, NULL);
    screen_sprite_flip(self->t_sprite, 0);
}