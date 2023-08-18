/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

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

static void calc_vals(level_gen_t *n[11], double *v, double d, int i)
{
    v[0] = ABS(n[9]->values[i] - n[10]->values[i]) * 3 - 2;
    v[0] = v[0] + 1 - d * 20;
    v[1] = ABS(n[0]->values[i] - n[1]->values[i]);
    v[1] = ABS(v[1] - n[2]->values[i]) * 3 - 2;
    v[2] = ABS(n[3]->values[i] - n[4]->values[i]);
    v[2] = ABS(v[1] - n[5]->values[i]) * 3 - 2;
    v[3] = ABS(n[6]->values[i] - n[7]->values[i]);
    v[3] = ABS(v[1] - n[8]->values[i]) * 3 - 2;
}

void generate_cave(level_gen_t *n[11], int *m, sfVector2i s, int depth)
{
    int i = 0;
    double val[4];
    double dist;

    for (int y = 0; y < s.y; y++) {
        for (int x = 0; x < s.x; x++) {
            i = x + y * s.x;
            dist = calc_dist(x, y, s);
            calc_vals(n, val, dist, i);
            m[i] = T_ROCK;
            if (val[0] > -2.0 && val[3] < -2.0 + (depth) / 2 * 3)
                m[i] = (depth > 2) ? (T_LAVA) : (T_WATER);
            if (val[0] > -2 && (val[1] < -1.5 || val[2] < -1.4))
                m[i] = T_DIRT;
        }
    }
}