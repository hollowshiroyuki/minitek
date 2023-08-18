/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "screen.h"
#include "consts.h"

void screen_init(screen_t *self, asset_store_t *assets, sfRenderWindow *win)
{
    if (!self)
        return;
    self->size = render_size;
    self->offset = (sfVector2i){0};
    self->win = win;
    self->e_sprite = sfSprite_create();
    sfSprite_setTexture(self->e_sprite, assets->entities, sfFalse);
    self->g_sprite = sfSprite_create();
    sfSprite_setTexture(self->g_sprite, assets->gui, sfFalse);
    self->t_sprite = sfSprite_create();
    sfSprite_setTexture(self->t_sprite, assets->tiles, sfFalse);
    self->i_sprite = sfSprite_create();
    sfSprite_setTexture(self->i_sprite, assets->items, sfFalse);
}