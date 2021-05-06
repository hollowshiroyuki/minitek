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

void furniture_recipe_craft(recipe_t *self, entity_t *player)
{
    entity_t *furniture = (*self->fur.create_furniture)();
    item_t *result = furniture_item_create(furniture);

    inventory_add(player->mob.pla.inventory, result);
}