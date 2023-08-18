/*
** EPITECH PROJECT, 2020
** hsy_str_isnum
** File description:
** if you code on paper, you're not a real programmer
*/

#include "hsy.h"

int hsy_str_isnum(char const *str)
{
    if (!str[0])
        return (1);
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || '9' < str[i]) {
            return (0);
        }
    }
    return (1);
}
