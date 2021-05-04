/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "items_id.h"
#include "entities/entity.h"

bool item_matches(item_t *self, item_t *item)
{
    if (self->id != item->id)
        return (false);
    if (self->id == I_RESOURCE)
        return (self->res.resource->id == item->res.resource->id);
    if (self->id == I_TOOL) {
        if (self->tool.type == item->tool.type) {
            return (self->tool.level == item->tool.level);
        } else {
            return (false);
        }
    }
    if (self->id == I_FURNITURE) {
        if (self->fur.furniture->id == item->fur.furniture->id) {
            return (true);
        }
    }
    return (false);
}