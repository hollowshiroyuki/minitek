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
    int val = hsy_atoi(split[5]);

    if (!(0 <= val && val <= 3)) {
        return (true);
    }
    return (false);
}

bool simple_mob_load(entity_t **e, char **split, int count)
{
    int id;
    int level;
    sfVector2i pos;
    bool error = false;

    if (count != 6 || check_split(split)) {
        return (true);
    }
    id = hsy_atoi(split[4]);
    level = hsy_atoi(split[5]);
    pos = (sfVector2i){hsy_atoi(split[2]), hsy_atoi(split[3])};
    if (id == MB_ZOMBIE)
        *e = zombie_create(level);
    if (id == MB_SLIME)
        *e = slime_create(level);
    (*e)->pos = pos;
    return (error);
}