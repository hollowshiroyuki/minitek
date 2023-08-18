/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"
#include "random.h"
#include "tiles_id.h"

maps_t level_gen_create_top_map(int w, int h)
{
    level_gen_t *noises[5];
    int *map = malloc(sizeof(int) * w * h);
    int *data = malloc(sizeof(int) * w * h);

    for (int i = 0; i < 5; i++)
        noises[i] = level_gen_create(w, h, (i > 2) ? (32) : (16));
    generate_island(noises, map, (sfVector2i){w, h});
    generate_sand(map, (sfVector2i){w, h});
    for (int i = 0; i < 5; i++)
        level_gen_destroy(noises[i]);
    return ((maps_t){map, data});
}