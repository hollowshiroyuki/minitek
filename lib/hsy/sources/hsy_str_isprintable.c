/*
** EPITECH PROJECT, 2020
** hsy_str_isprintable
** File description:
** well, real programmers use ed
*/

#include "hsy.h"

int hsy_str_isprintable(char const *str)
{
    if (!str[0])
        return (1);
    for (int i = 0; str[i]; i++) {
        if (str[i] < ' ' || str[i] == 127) {
            return (0);
        }
    }
    return (1);
}
