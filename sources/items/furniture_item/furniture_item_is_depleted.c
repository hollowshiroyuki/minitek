/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

bool furniture_item_is_depleted(item_t *self)
{
    return (self->fur.placed);
}