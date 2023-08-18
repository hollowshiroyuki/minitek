/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "screen.h"
#include "consts.h"

void screen_destroy(screen_t *self)
{
    if (!self)
        return;
    if (self->e_sprite)
        sfSprite_destroy(self->e_sprite);
    if (self->t_sprite)
        sfSprite_destroy(self->t_sprite);
    if (self->i_sprite)
        sfSprite_destroy(self->i_sprite);
    if (self->g_sprite)
        sfSprite_destroy(self->g_sprite);
}