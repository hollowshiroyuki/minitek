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
#include "items_id.h"

static bool check_split(char **split)
{
    int val;
    int min_values[] = {I_TOOL, 0, 0};
    int max_values[] = {I_TOOL, TT_COUNT - 1, 4};

    for (int i = 0; split[i]; i++) {
        val = hsy_atoi(split[i]);
        if (!(min_values[i] <= val && val <= max_values[i]))
            return (true);
    }
    return (false);
}

bool tool_item_load(item_t **itm, char **split, int count)
{
    int type;
    int level;
    bool error = false;

    if (count != 3 || check_split(split)) {
        return (true);
    }
    type = hsy_atoi(split[1]);
    level = hsy_atoi(split[2]);
    *itm = tool_item_create((tool_type_t *)tool_types[type], level);
    return (error);
}