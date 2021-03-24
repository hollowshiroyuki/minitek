/*
** EPITECH PROJECT, 2020
** hsy_strcapitalize
** File description:
** man man
*/

#include "hsy.h"

static int isalphanum(char c)
{
    if ('a' <= c && c <= 'z')
        return (3);
    if ('A' <= c && c <= 'Z')
        return (2);
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

char *hsy_strcapitalize(char *str)
{
    hsy_strlowcase(str);
    for (int i = 0; str[i]; i++) {
        if ((isalphanum(str[i]) > 1) && (i == 0 || !isalphanum(str[i - 1]))) {
            str[i] -= 'a' - 'A';
        }
    }
    return (str);
}
