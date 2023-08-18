/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus/title_menu.h"
#include "universe.h"

menu_t *title_menu_create(void)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->funcs = title_menu_funcs;
    return (new);
}