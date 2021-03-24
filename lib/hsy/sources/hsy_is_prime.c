/*
** EPITECH PROJECT, 2020
** hsy_is_prime
** File description:
** vim-epitech made by x4m3
*/

#include "hsy.h"

int hsy_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = nb - 1; i > 1; i--) {
        if (nb / i * i == nb) {
            return (0);
        }
    }
    return (1);
}
