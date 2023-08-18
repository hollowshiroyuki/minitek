/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "universe.h"
#include "hsy.h"
#include "floor.h"
#include "loader.h"
#include "entities_id.h"
#include "consts.h"

static bool check_split(char **split)
{
    sfVector2i s = map_size;
    int min_values[] = {E_MOB, 0, 0, 0, MB_PLAYER, 1};
    int max_values[] = {E_MOB, 15, s.x * 16 - 1, s.y * 16 - 1, MB_PLAYER, 30};
    int val;

    for (int i = 0; i < 6; i++) {
        if (!hsy_str_isnum(split[i]))
            return (true);
        val = hsy_atoi(split[i]);
        if (!(min_values[i] <= val && val <= max_values[i])) {
            return (true);
        }
    }
    return (false);
}

static void load_values(entity_t *e, char **split)
{
    e->id = E_MOB;
    e->floor = (void *)(long)hsy_atoi(split[1]);
    e->pos = (sfVector2i){hsy_atoi(split[2]), hsy_atoi(split[3])};
    e->mob.id = MB_PLAYER;
    e->mob.health = hsy_atoi(split[5]);
}

bool player_load(entity_t **player, FILE *file)
{
    int count = 0;
    char *str = get_line(file, false);
    char **split = str_split_count(str, ",", &count);
    bool error = false;

    *player = malloc(sizeof(entity_t));
    memset(*player, 0, sizeof(entity_t));
    entity_funcs_combine(&(*player)->funcs, &player_funcs, &mob_funcs);
    if (!str)
        return (true);
    if (count != 7 || check_split(split)) {
        free(split);
        return (true);
    }
    load_values(*player, split);
    error = inventory_load(&(*player)->mob.pla.inventory, split[6]);
    free(split);
    return (error);
}