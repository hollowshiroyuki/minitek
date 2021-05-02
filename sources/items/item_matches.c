/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

bool item_matches(item_t *self, item_t *item)
{
    return (self->id == item->id);
}