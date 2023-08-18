/*
** EPITECH PROJECT, 2020
** hsy_strncmp
** File description:
** r/ProgrammerHumor
*/

#include "hsy.h"

int hsy_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || !s1[i] || !s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}
