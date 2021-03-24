/*
** EPITECH PROJECT, 2020
** hsy_strncpy
** File description:
** https://github.com/x4m3/vim-epitech
*/

#include "hsy.h"

char *hsy_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i]; i++)
        dest[i] = src[i];
    for (int j = i; j < n; j++)
        dest[i] = '\0';
    return (dest);
}
