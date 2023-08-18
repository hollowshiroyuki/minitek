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
    char *dup = (char *)malloc(sizeof(char) * (len + 1));

    if (!dup)
        return (0);
    for (int i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return (dup);
}
