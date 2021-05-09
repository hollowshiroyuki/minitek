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
#include "resources/resources.h"
#include "resources_id.h"

static bool check_split(char **split)
{
    int val;
    int min_values[] = {I_RESOURCE, 0, 0};
    int max_values[] = {I_RESOURCE, R_COUNT - 1, 999};

    for (int i = 0; split[i]; i++) {
        val = hsy_atoi(split[i]);
        if (!(min_values[i] <= val && val <= max_values[i]))
            return (true);
    }
    return (false);
}

bool resource_item_load(item_t **itm, char **split, int count)
{
    int type;
    int quantity;
    resource_t *res;
    bool error = false;

    if (count != 3 || check_split(split)) {
        return (true);
    }
    type = hsy_atoi(split[1]);
    quantity = hsy_atoi(split[2]);
    res = resource_get(type);
    *itm = resource_item_create(res, quantity);
    return (error);
}