/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"

void level_gen_set_sample(level_gen_t *lg, int x, int y, double value)
{
    int w = lg->size.x;
    int h = lg->size.y;

    lg->values[(x & (w - 1)) + (y & (h - 1)) * w] = value;
}