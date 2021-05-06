/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"
#include "entities/entity.h"

void resource_recipe_craft(recipe_t *self, entity_t *player)
{
    resource_t *res = self->res.res;
    item_t *result = resource_item_create(res, self->res.count);

    inventory_add(player->mob.pla.inventory, result);
}