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
    int id;

    for (int i = 0; split[i]; i++) {
        if (!hsy_str_isnum(split[i])) {
            return (true);
        }
    }
    id = hsy_atoi(split[0]);
    if (id < 0 || id >= I_COUNT)
        return (true);
    return (false);
}

bool item_load(item_t **itm, char *str)
{
    int count = 0;
    int id;
    char **split = str_split_count(str, " ", &count);
    bool error = false;

    if (count < 2 || check_split(split)) {
        free(split);
        return (true);
    }
    id = hsy_atoi(split[0]);
    if (id == I_TOOL)
        error = tool_item_load(itm, split, count);
    if (id == I_FURNITURE)
        error = furniture_item_load(itm, split, count);
    if (id == I_RESOURCE)
        error = resource_item_load(itm, split, count);
    free(split);
    return (error);
}