/*
** EPITECH PROJECT, 2020
** hsy_str_to_word_array
** File description:
** csfml is the best thing ever
*/

#include <stdlib.h>

static int hsy_chr_isalphanum(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    if ('A' <= c && c <= 'Z')
        return (2);
    if ('a' <= c && c <= 'z')
        return (3);
    return (0);
}

static int count_words(char const *str)
{
    int words = 0;
    int in_word = 0;

    for (int i = 0; str[i]; i++) {
        if (hsy_chr_isalphanum(str[i]) && in_word == 0) {
                words += 1;
                in_word += 1;
        }
        if (!hsy_chr_isalphanum(str[i]) && in_word == 1)
            in_word = 0;
    }
    return (words);
}

static int count_until(char const *str)
{
    int i = 0;

    while (hsy_chr_isalphanum(str[i]))
        i++;
    return (i);
}

char **hsy_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **arr = (char **)malloc(sizeof(char *) * (words + 1));
    int k = 0;
    int len = 0;

    if (!arr)
        return (0);
    arr[words] = 0;
    for (int i = 0; i < words; i++) {
        while (!hsy_chr_isalphanum(str[k]))
            k++;
        len = count_until(str + k);
        arr[i] = (char *)malloc(sizeof(char) * (len + 1));
        arr[i][len] = '\0';
        for (int j = 0; j < len; j++)
            arr[i][j] = str[k++];
    }
    return (arr);
}
