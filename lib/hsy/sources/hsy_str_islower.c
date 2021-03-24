/*
** EPITECH PROJECT, 2020
** hsy_str_islower
** File description:
** example of bad code:
*/

#include "hsy.h"

int hsy_str_islower(char const *str)
{
    if (!str[0])
        return (1);
    for (int i = 0; str[i]; i++) {
        if (!('a' <= str[i] && str[i] <= 'z')) {
            return (0);
        }
    }
    return (1);
}
