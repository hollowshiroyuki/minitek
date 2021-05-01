/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"

void menu_destroy(menu_t *self)
{
    free(self);
}