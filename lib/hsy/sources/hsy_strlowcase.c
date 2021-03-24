/*
** EPITECH PROJECT, 2020
** hsy_strupcase
** File description:
** M-x doctor
*/

#include "hsy.h"

char *hsy_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    return (str);
}
