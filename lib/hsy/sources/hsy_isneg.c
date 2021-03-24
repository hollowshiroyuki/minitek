/*
** EPITECH PROJECT, 2020
** hsy_isneg
** File description:
** hey. real programmers use vim
*/

#include "hsy.h"

int hsy_isneg(int n)
{
    if (n < 0)
        hsy_putchar('N');
    else
        hsy_putchar('P');
    hsy_putchar('\n');
    return (0);
}
