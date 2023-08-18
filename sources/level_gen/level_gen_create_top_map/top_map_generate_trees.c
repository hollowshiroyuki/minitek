/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

void generate_trees(int *m, sfVector2i s)
{
    sfVector2i p[2];

    for (int i = 0; i < s.x * s.y / 400; i++) {
        p[0].x = random_int(s.x);
        p[0].y = random_int(s.y);
        for (int j = 0; j < 200; j++) {
            p[1].x = p[0].x + random_int(15) - random_int(15);
            p[1].y = p[0].y + random_int(15) - random_int(15);
            if (p[1].x < 0 || p[1].y < 0 || p[1].x >= s.x || p[1].y >= s.y)
                continue;
            if (m[p[1].x + p[1].y * s.x] == T_GRASS)
                m[p[1].x + p[1].y * s.x] = T_TREE;
        }
    }
}