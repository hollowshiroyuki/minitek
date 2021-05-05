/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus_id.h"
#include "menus/title_menu.h"
#include "universe.h"
#include "hsy.h"

menu_t *floor_change_menu_create(int dir)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_FLOOR_CHANGE;
    new->flc.time = 0;
    new->flc.dir = dir;
    new->funcs = floor_change_menu_funcs;
    return (new);
}