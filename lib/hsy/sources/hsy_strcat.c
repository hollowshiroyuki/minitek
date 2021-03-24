/*
** EPITECH PROJECT, 2020
** hsy_strcat
** File description:
** :wq
*/

#include "hsy.h"

char *hsy_strcat(char *dest, char const *src)
{
    int dest_len = hsy_strlen(dest);
    int i = 0;

    for (i = 0; src[i]; i++)
        dest[i + dest_len] = src[i];
    dest[i + dest_len] = '\0';
    return (dest);
}
