/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "resources/item.h"

void item_destroy(item_t *self)
{
    free(self);
}