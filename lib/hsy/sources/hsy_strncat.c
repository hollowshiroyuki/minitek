/*
** EPITECH PROJECT, 2020
** hsy_strncat
** File description:
** epitech > 42
*/

#include "hsy.h"

char *hsy_strncat(char *dest, char const *src, int nb)
{
    int dest_len = hsy_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && src[i]; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (dest);
}
