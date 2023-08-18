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
#include "consts.h"

static bool check_split(char **split)
{
    sfVector2i s = map_size;
    int min_values[] = {0, 0, 0, 0};
    int max_values[] = {E_COUNT - 1, 15, s.x * 16 - 1, s.y * 16 - 1};
    int val;

    for (int i = 0; i < 5; i++) {
        if (!hsy_str_isnum(split[i]))
            return (true);
        val = hsy_atoi(split[i]);
        if (i < 4 && !(min_values[i] <= val && val <= max_values[i])) {
            return (true);
        }
    }
    return (false);
}

bool entity_load(entity_t **e, char *str)
{
    int count = 0;
    int id;
    char **split = str_split_count(str, ",", &count);
    bool error = false;

    if (count < 5 || check_split(split)) {
        free(split);
        return (true);
    }
    id = hsy_atoi(split[0]);
    if (id == E_MOB)
        error = mob_load(e, split, count);
    if (id == E_ITEM)
        error = item_entity_load(e, split, count);
    if (id == E_FURNITURE)
        error = furniture_load(e, split, count);
    free(split);
    return (error);
}