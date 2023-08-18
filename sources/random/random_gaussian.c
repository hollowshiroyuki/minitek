/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "random.h"
#include "math.h"

float random_gaussian(void)
{
    double u;
    double v;
    double s;
    double fac;

    do {
        u = 2.0 * random_float() - 1;
        v = 2.0 * random_float() - 1;
        s = u * u + v * v;
    } while (s >= 1.0);
    fac = sqrt(-2.0 * log(s) / s);
    return (u * fac);
}