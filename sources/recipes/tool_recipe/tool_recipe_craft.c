/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

void tool_recipe_craft(recipe_t *self, entity_t *player)
{
    tool_type_t *tool_type = self->result->tool.type;
    item_t *result = tool_item_create(tool_type, self->result->tool.level);

    inventory_add(player->mob.pla.inventory, result);
}