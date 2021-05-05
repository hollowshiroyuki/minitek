/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "level_gen.h"
#include "random.h"
#include "tiles_id.h"

static void generate_stairs(int *m, sfVector2i s)
{
    int count = 0;
    sfVector2i p;
    bool enclosed;

    for (int i = 0; i < s.x * s.y / 100; i++) {
        enclosed = true;
        p.x = random_int(s.x - 2) + 1;
        p.y = random_int(s.y - 2) + 1;
        for (int y = p.y - 1; y <= p.y + 1; y++) {
            for (int x = p.x - 1; x <= p.x + 1; x++) {
                enclosed = (m[x + y * s.x] != T_ROCK) ? (false) : (enclosed);
            }
        }
        if (!enclosed)
            continue;
        m[p.x + p.y * s.x] = T_STAIRDOWN;
        count++;
        if (count == 6)
            return;
    }
}

maps_t level_gen_create_top_map(int w, int h)
{
    level_gen_t *noises[5];
    int *map = malloc(sizeof(int) * w * h);
    int *data = malloc(sizeof(int) * w * h);

    for (int i = 0; i < 5; i++)
        noises[i] = level_gen_create(w, h, (i > 2) ? (32) : (16));
    memset(data, 0, sizeof(int) * w * h);
    generate_island(noises, map, (sfVector2i){w, h});
    generate_sand(map, (sfVector2i){w, h});
    generate_trees(map, (sfVector2i){w, h});
    generate_cactus(map, (sfVector2i){w, h});
    generate_flowers((maps_t){map, data}, (sfVector2i){w, h});
    generate_stairs(map, (sfVector2i){w, h});
    for (int i = 0; i < 5; i++)
        level_gen_destroy(noises[i]);
    return ((maps_t){map, data});
}