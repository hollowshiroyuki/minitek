/*
** EPITECH PROJECT, 2020
** hsy_str_isupper
** File description:
** r/ProgrammerHumor
*/

#include "hsy.h"

int hsy_str_isupper(char const *str)
{
    if (!str[0])
        return (1);
    for (int i = 0; str[i]; i++) {
        if (!('A' <= str[i] && str[i] <= 'Z')) {
            return (0);
        }
    }
    return (1);
}
