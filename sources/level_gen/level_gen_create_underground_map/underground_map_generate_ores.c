/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

void generate_ores(int *m, sfVector2i s, int depth)
{
    int r = 2;
    sfVector2i p[2];

    for (int i = 0; i < s.x * s.y / 400; i++) {
        p[0].x = random_int(s.x);
        p[0].y = random_int(s.y);
        for (int j = 0; j < 30; j++) {
            p[1].x = p[0].x + random_int(5) - random_int(5);
            p[1].y = p[0].y + random_int(5) - random_int(5);
            if (p[1].x < r || p[1].y < r)
                continue;
            if (p[1].x >= s.x - r || p[1].y >= s.y - r)
                continue;
            if (m[p[1].x + p[1].y * s.x] == T_ROCK)
                m[p[1].x + p[1].y * s.x] = T_IRON + depth - 1;
        }
    }
}