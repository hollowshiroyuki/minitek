/*
** EPITECH PROJECT, 2020
** hsy_str_is_aplha
** File description:
** epitech > epita
*/

#include "hsy.h"

int hsy_str_isalpha(char const *str)
{
    if (!str[0])
        return (1);
    for (int i = 0; str[i]; i++) {
        if (str[i] < 'A' || ('Z' < str[i] && str[i] < 'a') || 'z' < str[i])
            return (0);
    }
    return (1);
}
