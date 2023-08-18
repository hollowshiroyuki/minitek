/*
** EPITECH PROJECT, 2020
** hsy_find_prime_sup
** File description:
** example of bad code:
*/

#include "hsy.h"

int hsy_find_prime_sup(int nb)
{
    if (hsy_is_prime(nb))
        return (nb);
    return (hsy_find_prime_sup(nb + 1));
}
