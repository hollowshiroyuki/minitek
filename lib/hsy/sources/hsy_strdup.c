/*
** EPITECH PROJECT, 2020
** hsy_strdup
** File description:
** echo $?
*/

#include <stdlib.h>
#include "hsy.h"

char *hsy_strdup(char const *str)
{
    int len = hsy_strlen(str);
    char *dup;

    if (!str)
        return (0);
    if (!(dup = malloc(sizeof(char) * (len + 1))))
        return (0);
    for (int i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return (dup);
}
