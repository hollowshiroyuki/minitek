/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "items_id.h"
#include "recipes/craft.h"

void recipe_deduct_cost(recipe_t *self, entity_t *player)
{
    item_t *cur = self->cost;
    inventory_t *inv = player->mob.pla.inventory;

    while (cur) {
        if (cur->id == I_RESOURCE) {
            inventory_remove_resource(inv, cur->res.resource, cur->res.count);
        }
        cur = cur->next;
    }
}