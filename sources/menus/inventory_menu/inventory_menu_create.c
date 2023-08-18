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

menu_t *inventory_menu_create(entity_t *player, char *title)
{
    menu_t *new = malloc(sizeof(menu_t));
    inventory_t *inv = player->mob.pla.inventory;


    memset(new, 0, sizeof(menu_t));
    new->id = M_INVENTORY;
    new->inv.player = player;
    new->name = hsy_strdup(title);
    if (player->mob.pla.active_item) {
        inventory_add_pos(inv, player->mob.pla.active_item, 1);
        player->mob.pla.active_item = NULL;
    }
    new->funcs = inventory_menu_funcs;
    return (new);
}