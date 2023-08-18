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

    if (!(0 <= val && val <= MB_COUNT - 1) || val == MB_PLAYER) {
        return (true);
    }
    return (false);
}

bool mob_load(entity_t **e, char **split, int count)
{
    int id;
    bool error = false;

    if (count < 5 || check_split(split)) {
        return (true);
    }
    id = hsy_atoi(split[4]);
    if (id == MB_ZOMBIE || id == MB_SLIME)
        error = simple_mob_load(e, split, count);
    return (error);
}