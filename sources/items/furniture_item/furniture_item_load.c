/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdbool.h>
#include <stdio.h>
#include "universe.h"
#include "hsy.h"
#include "floor.h"
#include "loader.h"
#include "items_id.h"

static bool check_split(char **split)
{
    int val;
    int min_values[] = {I_FURNITURE, 0};
    int max_values[] = {I_FURNITURE, F_COUNT - 1};

    for (int i = 0; split[i]; i++) {
        val = hsy_atoi(split[i]);
        if (!(min_values[i] <= val && val <= max_values[i]))
            return (true);
    }
    return (false);
}

bool furniture_item_load(item_t **itm, char **split, int count)
{
    int furniture_id;
    entity_t *furniture;
    bool error = false;

    if (count != 2 || check_split(split)) {
        return (true);
    }
    furniture_id = hsy_atoi(split[1]);
    furniture = furniture_create(furniture_id);
    *itm = furniture_item_create(furniture);
    return (error);
}