/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

void generate_cactus(int *m, sfVector2i s)
{
    for (int i = 0; i < s.x * s.y / 50; i++) {
        int x = random_int(s.x);
        int y = random_int(s.y);
        if (x < 0 || y < 0 || x >= s.x || y >= s.y)
            continue;
        if (m[x + y * s.x] == T_SAND)
            m[x + y * s.x] = T_CACTUS;
    }
}