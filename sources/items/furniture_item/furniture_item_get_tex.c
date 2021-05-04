/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "entities/entity.h"

int furniture_item_get_tex(item_t *self)
{
    return (self->fur.furniture->fur.tex + 26 * 32);
}