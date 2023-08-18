/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include "consts.h"
#include "floor.h"
#include "entities/entity.h"

void floor_entities_row_clear(entity_t **row, int len)
{
    memset(row, 0, sizeof(entity_t *) * ((entities_per_tile) * len));
}