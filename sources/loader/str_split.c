/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "hsy.h"

static int count_words(char *str, char *delim)
{
    int res = 1;
    int delim_len = hsy_strlen(delim);

    while ((str = hsy_strstr(str, delim))) {
        str += delim_len;
        res++;
    }
    return (res);
}

static char **str_split_(char *s, char *delim, int *nb)
{
    int nb_words = count_words(s, delim);
    int ptrs_size = (nb_words + 1) * sizeof(char *);
    int s_len = hsy_strlen(s);
    int delim_len = hsy_strlen(delim);
    void *data = malloc(ptrs_size + s_len + 1);
    char *tmp = hsy_strcpy(((char *)data) + ptrs_size, s);
    const char **ptrs = data;

    *ptrs = tmp;
    if (nb_words > 1) {
        while ((tmp = hsy_strstr(tmp, delim))) {
            *tmp = '\0';
            tmp += delim_len;
            *++ptrs = tmp;
        }
    }
    *++ptrs = NULL;
    if (nb)
        *nb = data ? nb_words : 0;
    return (data);
}

char **str_split(char *s, char *delim)
{
    if (!s)
        return (0);
    return (str_split_(s, delim, 0));
}

char **str_split_count(char *s, char *delim, int *nb)
{
    if (!s)
        return (0);
    return (str_split_(s, delim, nb));
}