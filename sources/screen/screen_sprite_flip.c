/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "screen.h"
#include "consts.h"

void screen_sprite_flip(sfSprite *sprite, int m)
{
    sfIntRect r = sfSprite_getTextureRect(sprite);
    sfVector2f s = (sfVector2f){r.width, r.height};
    sfVector2f sc = (sfVector2f){(m & HOR_F) ? -1 : 1, (m & VER_F) ? -1 : 1};
    sfVector2f o = (sfVector2f){(m & HOR_F) ? s.x : 0, (m & VER_F) ? s.y : 0};

    sfSprite_setOrigin(sprite, o);
    sfSprite_setScale(sprite, sc);
}