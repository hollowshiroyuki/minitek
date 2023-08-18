/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"

void title_menu_destroy(menu_t *self)
{
    sfTexture_destroy(self->title.texture);
    sfSprite_destroy(self->title.background);
    menu_destroy(self);
}