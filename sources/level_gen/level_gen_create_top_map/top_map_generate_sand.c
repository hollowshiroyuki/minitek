/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

static void generate_sand_patch(int *m, sfVector2i s, sfVector2i o)
{
    for (int yy = o.y - 1; yy <= o.y + 1; yy++) {
        for (int xx = o.x - 1; xx <= o.x + 1; xx++) {
            if (xx < 0 || yy < 0 || xx >= s.x || yy >= s.y)
                continue;
            if (m[xx + yy * s.x] == T_GRASS)
                m[xx + yy * s.x] = T_SAND;
        }
    }
}

void generate_sand(int *m, sfVector2i s)
{
    sfVector2i p[3];

    for (int i = 0; i < s.x * s.y / 2800; i++) {
        p[1].x = random_int(s.x);
        p[1].y = random_int(s.y);
        for (int k = 0; k < 10; k++) {
            p[0].x = p[1].x + random_int(21) - 10;
            p[0].y = p[1].y + random_int(21) - 10;
            for (int j = 0; j < 100; j++) {
                p[2].x = p[0].x + random_int(5) - random_int(5);
                p[2].y = p[0].y + random_int(5) - random_int(5);
                generate_sand_patch(m, s, p[2]);
            }
        }
    }
}