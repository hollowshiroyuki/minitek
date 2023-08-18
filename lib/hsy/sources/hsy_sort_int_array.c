/*
** EPITECH PROJECT, 2020
** hsy_sort_int_array
** File description:
** xkcd.com/378
*/

#include "hsy.h"

void hsy_sort_int_array(int *array, int size)
{
    int swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            hsy_int_swap(&array[i], &array[i + 1]);
            swaps += 1;
        }
    }
    if (swaps != 0)
        hsy_sort_int_array(array, size);
}
