/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

int resource_item_get_tex(item_t *self)
{
    return (self->res.resource->tex);
}