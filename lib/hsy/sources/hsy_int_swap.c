/*
** EPITECH PROJECT, 2020
** hsy_swap
** File description:
** r/ProgrammerHumor
*/

#include "hsy.h"

void hsy_int_swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}
