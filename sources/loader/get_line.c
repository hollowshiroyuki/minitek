/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *get_line(FILE *file, bool fre)
{
    static char *str = 0;
    static size_t b_len = 0;
    static ssize_t len = 0;

    if (fre && str) {
        free(str);
        str = 0;
        return (0);
    }
    len = getline(&str, &b_len, file);
    if (len == -1) {
        free(str);
        return (0);
    }
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
    return (str);
}