/*
** EPITECH PROJECT, 2020
** hsy_strupcase
** File description:
** M-x doctor
*/

#include "hsy.h"

char *hsy_strupcase(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
    }
    return (str);
}
