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

static FILE *open_save_file(char *filename)
{
    char path[PATH_MAX];
    FILE *file;

    hsy_strcpy(path, "./saves/");
    hsy_strcat(path, filename);
    file = fopen(path, "r");
    if (!file) {
        hsy_fd_putstr(2, "Can't open folder or file. Can't load the game.\n");
        return (0);
    }
    return (file);
}

bool load_seeds(int seeds[2], FILE *file)
{
    char *str = get_line(file, false);
    int count = 0;
    char **split = str_split_count(str, ",", &count);

    if (!str)
        return (true);
    if (count != 2) {
        free(split);
        return (true);
    }
    seeds[0] = parse_atoi(&split[0]);
    seeds[1] = parse_atoi(&split[1]);
    return (false);
}

static bool floors_load(floor_t *floors[16], FILE *file)
{
    bool error = 0;
    char *str;
    floor_t *tmp = 0;
    int i;

    for (i = 0; !error && i < 16; i++) {
        str = get_line(file, false);
        if (str && !hsy_strcmp("FLOOR", str)) {
            error = floor_load(&tmp, file);
            if (!error && tmp)
                floors[i] = tmp;
            tmp = 0;
        }
        else
            break;
    }
    if (i < 3)
        return (true);
    return (error);
}

universe_t *universe_load_from_file(char *name)
{
    FILE *file = open_save_file(name);
    universe_t *new = malloc(sizeof(universe_t));
    bool error = false;

    if (!file)
        return (0);
    memset(new, 0, sizeof(universe_t));
    new->name = hsy_strdup(name);
    error = load_seeds(new->seeds, file);
    if (!error)
        error = player_load(&new->player, file);
    if (!error)
        error = floors_load(new->floors, file);
    if (error || !new->floors[(long)new->player->floor]) {
        fclose(file);
        universe_destroy(new);
        return (0);
    }
    get_line(file, true);
    fclose(file);
    return (new);
}