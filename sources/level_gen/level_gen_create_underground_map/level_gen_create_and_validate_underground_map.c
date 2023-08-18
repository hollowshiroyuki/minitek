/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdbool.h>
#include "level_gen.h"
#include "random.h"
#include "tiles_id.h"

static bool underground_map_is_valid(int *map, int depth)
{
    bool is_valid = true;

    depth = (depth % 3);
    is_valid = (map[T_ROCK] < 100) ? (false) : (is_valid);
    is_valid = (map[T_DIRT] < 100) ? (false) : (is_valid);
    is_valid = (map[T_IRON + depth] < 20) ? (false) : (is_valid);
    is_valid = (map[T_STAIRDOWN] < 2) ? (false) : (is_valid);
    return (is_valid);
}

maps_t level_gen_create_and_validate_underground_map(int w, int h, int depth)
{
    maps_t maps;
    int tiles_count[T_COUNT];

    do {
        for (int i = 0; i < T_COUNT; i++)
            tiles_count[i] = 0;
        maps = level_gen_create_underground_map(w, h, depth);
        for (int i = 0; i < w * h; i++) {
            tiles_count[maps.map[i]] += 1;
        }
    } while (!underground_map_is_valid(tiles_count, depth));
    return (maps);
}