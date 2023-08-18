/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"
#include "resources/resource.h"

item_t *inventory_find_resource(inventory_t *self, resource_t *res)
{
    item_t *tmp = self->items;

    while (tmp) {
        if (tmp->id == I_RESOURCE) {
            if (tmp->res.resource->id == res->id) {
                return (tmp);
            }
        }
        tmp = tmp->next;
    }
    return (0);
}