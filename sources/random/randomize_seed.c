/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include "hsy.h"

static int randomize_from_file(FILE *in)
{
    unsigned int seed = 0;

    if (!in)
        return (-1);
    if (fread(&seed, sizeof(seed), 1, in) == 1) {
        fclose(in);
        srand(seed);
        return (0);
    }
    fclose(in);
    return (-1);
}

int randomize_seed(void)
{
    if (!randomize_from_file(fopen("/dev/urandom", "r")))
        return (0);
    if (!randomize_from_file(fopen("/dev/arandom", "r")))
        return (0);
    if (!randomize_from_file(fopen("/dev/random", "r")))
        return (0);
    hsy_fd_putstr(2, "[WARN] No suitable random source found for seeding !\n");
    return (-1);
}