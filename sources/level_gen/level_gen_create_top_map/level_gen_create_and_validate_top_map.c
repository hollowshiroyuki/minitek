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

bool top_map_is_valid(int *map)
{
    bool is_valid = true;
    
    is_valid = (map[T_ROCK] < 100) ? (false) : (is_valid);
    is_valid = (map[T_SAND] < 100) ? (false) : (is_valid);
    is_valid = (map[T_GRASS] < 100) ? (false) : (is_valid);
    is_valid = (map[T_TREE] < 100) ? (false) : (is_valid);
    is_valid = (map[T_STAIRDOWN] < 2) ? (false) : (is_valid);
    return (is_valid);
}

maps_t level_gen_create_and_validate_top_map(int w, int h)
{
    maps_t maps;
    int tiles_count[T_COUNT];

    for (int i = 0; i < T_COUNT; i++)
        tiles_count[i] = 0;
    do {
        maps = level_gen_create_top_map(w, h);
        for (int i = 0; i < w * h; i++) {
            tiles_count[maps.map[i]] += 1;
        }
    } while (!top_map_is_valid(tiles_count));
    return (maps);
}