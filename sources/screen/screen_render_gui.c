/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "screen.h"
#include <stdio.h>

void sprite_flip(sfSprite *sprite, int m)
{
    sfIntRect r = sfSprite_getTextureRect(sprite);
    sfVector2f sz = (sfVector2f){r.width, r.height};
    sfVector2f sc = (sfVector2f){(m & HOR_F) ? -1 : 1, (m & VER_F) ? -1 : 1};
    sfVector2f o = (sfVector2f){(m & HOR_F) ? sz.x : 0, (m & VER_F) ? sz.y : 0};

    sfSprite_setOrigin(sprite, o);
    sfSprite_setScale(sprite, sc);
}

void screen_render_gui(screen_t *self, sfVector2i pos, int tile_id, int flip)
{
    sfVector2i tile = {(tile_id % 32) * 8, (tile_id / 32) * 8};
    sfIntRect rect = {tile.x, tile.y, 8, 8};

    pos.x -= self->offset.x;
    pos.y -= self->offset.y;
    if (pos.x < -8 || pos.x >= self->size.x + 8)
        return;
    if (pos.y < -8 || pos.y >= self->size.y + 8)
        return;
    sfSprite_setTextureRect(self->g_sprite, rect);
    sprite_flip(self->g_sprite, flip);
    sfSprite_setPosition(self->g_sprite, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawSprite(self->win, self->g_sprite, NULL);
    sprite_flip(self->g_sprite, 0);
}