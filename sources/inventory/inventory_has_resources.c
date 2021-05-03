/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "inventory.h"
#include "items_id.h"
#include "resources/resource.h"

bool inventory_has_resources(inventory_t *self, resource_t *res, int count)
{
    item_t *has = inventory_find_resource(self, res);

    if (!has)
        return (false);
    if (has->res.count < count)
        return (false);
    return (true);
}