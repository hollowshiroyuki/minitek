/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "screen.h"

void screen_set_offset(screen_t *self, sfVector2i offset)
{
    self->offset = offset;
}