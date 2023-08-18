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

static void generate_stairs(int *m, sfVector2i s)
{
    int count = 0;
    sfVector2i p;
    bool enclosed;

    for (int i = 0; i < s.x * s.y / 100; i++) {
        enclosed = true;
        p.x = random_int(s.x - 20) + 10;
        p.y = random_int(s.y - 20) + 10;
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

void level_gen_generate_underground_map(maps_t *maps, int w, int h, int depth)
{
    level_gen_t *noises[11];

    depth = (depth % 3) + 1;
    memset(maps->data, 0, sizeof(int) * w * h);
    generate_noise(noises, (sfVector2i){w, h});
    generate_cave(noises, maps->map, (sfVector2i){w, h}, depth);
    generate_ores(maps->map, (sfVector2i){w, h}, depth);
    generate_stairs(maps->map, (sfVector2i){w, h});
    destroy_noise(noises);
}

maps_t level_gen_create_underground_map(int w, int h, int depth)
{
    maps_t maps;
    maps.map = malloc(sizeof(int) * w * h);
    maps.data = malloc(sizeof(int) * w * h);

    level_gen_generate_underground_map(&maps, w, h, depth);
    return (maps);
}
