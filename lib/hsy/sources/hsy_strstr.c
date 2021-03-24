/*
** EPITECH PROJECT, 2020
** hsy_strstr
** File description:
** vim > emacs
*/

#include "hsy.h"

static char *check_str(char *str, char const *to_find)
{
    if (hsy_strlen(str) < hsy_strlen(to_find))
        return (0);
    for (int i = 0; to_find[i]; i++)
        if (str[i] != to_find[i])
            return (0);
    return (str);
}

char *hsy_strstr(char *str, char const *to_find)
{
    char *ret = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == to_find[0]) {
            ret = check_str(str + i, to_find);
        }
        if (ret) {
            return (ret);
        }
    }
    return (0);
}
