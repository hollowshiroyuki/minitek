/*
** EPITECH PROJECT, 2020
** hsy_revstr
** File description:
** code on paper!
*/

#include "hsy.h"

char *hsy_revstr(char *str)
{
    int len = hsy_strlen(str);

    for (int i = 0; i < len / 2; i++) {
        str[i] = str[i] ^ str[len - 1 - i];
        str[len - 1 - i] = str[len - 1 - i] ^ str[i];
        str[i] = str[i] ^ str[len - 1 - i];
    }
    return (str);
}
