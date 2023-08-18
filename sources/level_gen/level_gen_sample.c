/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "level_gen.h"

double level_gen_sample(level_gen_t *lg, int x, int y)
{
    int w = lg->size.x;
    int h = lg->size.y;

    return (lg->values[(x & (w - 1)) + (y & (h - 1)) * w]);
}