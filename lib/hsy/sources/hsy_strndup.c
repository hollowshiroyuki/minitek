/*
** EPITECH PROJECT, 2021
** libhsy [WSL: Ubuntu-20.04]
** File description:
** hsy_strndup
*/

#include "hsy.h"
#include <stdlib.h>

char *hsy_strndup(char const *str, size_t n)
{
    size_t len = hsy_strlen(str) + 1;
    char *dup = 0;

    len = (len > n) ? n + 1 : len;
    if (!(dup = malloc(sizeof(char) * len)))
        return (0);
    dup[len - 1] = '\0';
    for (size_t i = 0; i < len; i++) {
        dup[i] = str[i];
    }
    return (dup);
}