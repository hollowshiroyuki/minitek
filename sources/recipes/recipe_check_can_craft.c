/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"
#include "resources/item.h"
#include "items_id.h"

void recipe_check_can_craft(recipe_t *self, entity_t *player)
{
    item_t *cost = self->cost;
    resource_item_t *res;
    inventory_t *inv = player->mob.pla.inventory;

    while (cost) {
        if (cost->id == I_RESOURCE) {
            res = &cost->res;
            if (inventory_has_resources(inv, res->resource, res->count)) {
                self->can_craft = false;
                return;
            }
        }
        cost = cost->next;
    }
    self->can_craft = true;
}