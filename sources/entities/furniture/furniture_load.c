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

static bool check_split(char **split)
{
    int val = hsy_atoi(split[4]);

    if (!(0 <= val && val <= F_COUNT - 1)) {
        return (true);
    }
    return (false);
}

bool furniture_load(entity_t **e, char **split, int count)
{
    int type;
    sfVector2i pos;
    bool error = false;

    if (count != 5 || check_split(split)) {
        return (true);
    }
    type = hsy_atoi(split[4]);
    pos = (sfVector2i){hsy_atoi(split[2]), hsy_atoi(split[3])};
    if (!error)
        *e = furniture_create(type);
    (*e)->pos = pos;
    return (error);
}