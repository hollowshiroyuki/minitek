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

static bool check_split(char **split)
{
    if (split[0][0] != 'I')
        return (true);
    if (!hsy_str_isnum(split[1]))
        return (true);
    if (hsy_atoi(split[1]) < 1)
        return (true);
    return (false);
}

static void load_values(inventory_t *i, char **split)
{
    i->capacity = hsy_atoi(split[1]);
}

static bool load_items(inventory_t *inv, char **split)
{
    item_t *tmp = 0;
    bool error = false;

    for (int i = 0; !error && split[i]; i++) {
        error = item_load(&tmp, split[i]);
        if (!tmp)
            break;
        inventory_add(inv, tmp);
        tmp = 0;
    }
    return (error);
}

bool inventory_load(inventory_t **inv, char *str)
{
    int count = 0;
    char **split = str_split_count(str, "|", &count);
    bool error = false;

    *inv = malloc(sizeof(inventory_t));
    memset(*inv, 0, sizeof(inventory_t));
    if (count < 2 || check_split(split)) {
        free(split);
        return (true);
    }
    load_values(*inv, split);
    if (count >= 3)
        error = load_items(*inv, &split[2]);
    free(split);
    return (error);
}