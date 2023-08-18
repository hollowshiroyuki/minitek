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

menu_t *inventory_menu_create(entity_t *player)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_INVENTORY;
    new->inv.player = player;
    if (player->mob.pla.active_item) {
        inventory_add(player->mob.pla.inventory, player->mob.pla.active_item);
        player->mob.pla.active_item = NULL;
    }
    new->funcs = inventory_menu_funcs;
    return (new);
}