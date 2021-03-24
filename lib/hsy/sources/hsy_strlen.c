/*
** EPITECH PROJECT, 2020
** hsy_strlen
** File description:
** xkcd.com/378
*/

#include "hsy.h"

size_t hsy_strlen(char const *str)
{
    size_t i = 0;
    while (str[i]) {
        i++;
    }
    return (i);
}
