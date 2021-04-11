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

static void generate_noise(level_gen_t *n[11], sfVector2i size)
{
    for (int i = 0; i < 11; i++) {
        n[i] = level_gen_create(size.x, size.y, (i > 9) ? (32) : (16));
    }
}

static void destroy_noise(level_gen_t *n[11])
{
    for (int i = 0; i < 11; i++) {
        level_gen_destroy(n[i]);
    }
}

maps_t level_gen_create_underground_map(int w, int h, int depth)
{
    level_gen_t *noises[11];
    int *map = malloc(sizeof(int) * w * h);
    int *data = malloc(sizeof(int) * w * h);

    depth = (depth % 3) + 1;
    generate_noise(noises, (sfVector2i){w, h});
    generate_cave(noises, map, (sfVector2i){w, h}, depth);
    generate_ores(map, (sfVector2i){w, h}, depth);
    destroy_noise(noises);
    return ((maps_t){map, data});
}