/*
** EPITECH PROJECT, 2020
** hsy_strcpy
** File description:
** example of bad code:
*/

#include "hsy.h"

char *hsy_strcpy(char *dest, char const *src)
{
    size_t len = hsy_strlen(src);

    return (hsy_strncpy(dest, src, len + 1));
}
