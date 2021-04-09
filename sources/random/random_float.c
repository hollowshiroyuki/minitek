/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>

float random_float(void)
{
    return ((float)((double)rand() / (double)(RAND_MAX / 1)));
}