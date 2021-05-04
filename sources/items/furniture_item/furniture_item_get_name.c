/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "entities/entity.h"

char *furniture_item_get_name(item_t *self)
{
    return (self->fur.furniture->fur.name);
}