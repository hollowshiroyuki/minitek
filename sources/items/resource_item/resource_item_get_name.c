/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

char *resource_item_get_name(item_t *self)
{
    return (self->res.resource->name);
}