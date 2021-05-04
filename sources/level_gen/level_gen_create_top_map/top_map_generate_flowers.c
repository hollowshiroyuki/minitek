/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

void generate_flowers(maps_t m, sfVector2i s)
{
    sfVector2i p[2];
    int col = 0;

    for (int i = 0; i < s.x * s.y / 400; i++) {
        p[0].x = random_int(s.x);
        p[0].y = random_int(s.y);
        col = random_int(4);
        for (int j = 0; j < 30; j++) {
            p[1].x = p[0].x + random_int(5) - random_int(5);
            p[1].y = p[0].y + random_int(5) - random_int(5);
            if (p[1].x < 0 || p[1].y < 0 || p[1].x >= s.x || p[1].y >= s.y)
                continue;
            if (m.map[p[1].x + p[1].y * s.x] == T_GRASS) {
                m.map[p[1].x + p[1].y * s.x] = T_FLOWER;
                m.data[p[1].x + p[1].y * s.x] = (col + random_int(4)) * 16;
            }
        }
    }
}