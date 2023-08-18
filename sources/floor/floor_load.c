/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdbool.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "universe.h"
#include "hsy.h"
#include "floor.h"
#include "loader.h"
#include "tiles_id.h"
#include "consts.h"

static bool load_data(int **map, FILE *file)
{
    int count;
    bool error = false;
    char *str = get_line(file, false);
    char **split;

    *map = malloc(sizeof(int) * map_size.x * map_size.y);
    split = str_split_count(str, ",", &count);
    if (!str || !(*map))
        return (true);
    if (count != map_size.x * map_size.y) {
        free(split);
        return (true);
    }
    for (int i = 0; !error && split[i]; i++) {
        (*map)[i] = hsy_atoi(split[i]);
        if (!hsy_str_isnum(split[i]))
            error = true;
    }
    free(split);
    return (error);
}

static bool load_entities(entity_t **list, FILE *file)
{
    bool error = false;
    entity_t *tmp = 0;
    char *str;

    while (!error && (str = get_line(file, false))) {
        if (!str)
            error = true;
        else {
            if (!hsy_strcmp("END_FLOOR", str))
                break;
            error = entity_load(&tmp, str);
            if (!error && tmp) {
                entities_add(list, tmp);
                tmp = 0;
            }
        }
    }
    if (!str)
        error = true;
    return (error);
}

static bool load_map(int **map, FILE *file)
{
    int count;
    bool error = false;
    char *str = get_line(file, false);
    char **split;

    *map = malloc(sizeof(int) * map_size.x * map_size.y);
    split = str_split_count(str, ",", &count);
    if (!str || !(*map))
        return (true);
    if (count != map_size.x * map_size.y) {
        free(split);
        return (true);
    }
    for (int i = 0; !error && split[i]; i++) {
        (*map)[i] = hsy_atoi(split[i]);
        if (!hsy_str_isnum(split[i]) || 0 > (*map)[i] || (*map)[i] >= T_COUNT)
            error = true;
    }
    free(split);
    return (error);
}

bool floor_load(floor_t **floor, FILE *file)
{
    bool error = false;
    int *map = 0;
    int *data = 0;

    *floor = malloc(sizeof(floor_t));
    memset(*floor, 0, sizeof(floor_t));
    hsy_putstr("Loading floor tiles...\n");
    error = load_map(&(*floor)->tiles, file);
    if (!error){
        hsy_putstr("Loading floor data...\n");
        error = load_data(&(*floor)->data, file);
    }
    if (!error) {
        error = load_entities(&(*floor)->entities, file);
        hsy_putstr("Loading floor entities...\n");
    }
    return (error);
}