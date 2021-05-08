/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"
#include "items_id.h"
#include "resources/item.h"
#include "hsy.h"

void item_save(item_t *self, int fd)
{
    if (self->id == I_FURNITURE)
        furniture_item_save(self, fd);
    if (self->id == I_TOOL)
        tool_item_save(self, fd);
    if (self->id == I_RESOURCE)
        resource_item_save(self, fd);
}