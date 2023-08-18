/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universe.h"
#include "hsy.h"
#include "floor.h"
#include "loader.h"
#include "entities_id.h"

bool item_entity_load(entity_t **e, char **split, int count)
{
    int id;
    item_t *item = 0;
    sfVector2i pos;
    bool error = false;

    if (count != 6) {
        return (true);
    }
    pos = (sfVector2i){hsy_atoi(split[2]), hsy_atoi(split[3])};
    error = item_load(&item, split[5]);
    if (!error && item)
        *e = item_entity_create(item, pos);
    return (error);
}