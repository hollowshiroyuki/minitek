/*
** EPITECH PROJECT, 2020
** hsy_compute_square_root
** File description:
** don't forget to free at the end
*/

#include "hsy.h"

int hsy_compute_square_root(int nb)
{
    if (nb <= 0)
        return (0);
    for (int i = 0; i * i <= nb; i++)
        if (i * i == nb)
            return (i);
    return (0);
}
