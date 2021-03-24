/*
** EPITECH PROJECT, 2020
** hsy_compute_power_rec
** File description:
** well, real programmers use ed
*/

#include "hsy.h"

int hsy_compute_power_rec(int nb, int p)
{
    int ret = 0;
    int old = nb;

    if (p < 0)
        return (0);
    if (p == 1)
        return (nb);
    if (p == 0)
        return (1);
    ret = nb * hsy_compute_power_rec(nb, p - 1);
    if (!((ret <= 0) ^ (old > 0)) && nb > 0)
        return (0);
    return (nb * hsy_compute_power_rec(nb, p - 1));
}
