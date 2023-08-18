/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"
#include "tiles_id.h"

static double calc_dist(int x, int y, sfVector2i s)
{
    double xd;
    double yd;
    double dist;

    xd = x / (s.x - 1.0) * 2 - 1;
    yd = y / (s.y - 1.0) * 2 - 1;
    xd = (xd < 0) ? (-xd) : (xd);
    yd = (yd < 0) ? (-yd) : (yd);
    dist =  (xd >= yd) ? (xd) : (yd);
    dist = dist * dist * dist * dist;
    dist = dist * dist * dist * dist;
    return (dist);
}

static void generate_island(level_gen_t *n[5], int *m, sfVector2i s)
{
    int i = 0;
    double val;
    double mval;
    double dist;

    for (int y = 0; y < s.y; y++) {
        for (int x = 0; x < s.x; x++) {
            i = x + y * s.x;
            val = ABS(n[0]->values[i] - n[1]->values[i]) * 3 - 2;
            mval = ABS(n[3]->values[i] - n[4]->values[i]);
            mval = ABS(mval - n[2]->values[i]) * 3 - 2;
            dist = calc_dist(x, y, s);
            val = val + 1 - dist * 20;
            m[i] = T_GRASS;
            if (val < -0.5)
                m[i] = T_WATER;
            if (val > 0.5 && mval < -1.5)
                m[i] = T_ROCK;
        }
    }
}

maps_t level_gen_create_top_map(int w, int h)
{
    level_gen_t *noises[5];
    int *map = malloc(sizeof(int) * w * h);
    int *data = malloc(sizeof(int) * w * h);

    for (int i = 0; i < 5; i++)
        noises[i] = level_gen_create(w, h, (i > 2) ? (32) : (16));
    generate_island(noises, map, (sfVector2i){w, h});
    for (int i = 0; i < 5; i++)
        level_gen_destroy(noises[i]);
    return ((maps_t){map, data});
}