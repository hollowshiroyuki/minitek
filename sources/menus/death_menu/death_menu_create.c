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
#include "universe.h"
#include "hsy.h"
#include <stdio.h>

menu_t *death_menu_create(entity_t *player)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_DEATH;
    new->dea.player = player;
    new->funcs = death_menu_funcs;
    return (new);
}