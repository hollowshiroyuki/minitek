/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "hsy.h"
#include "consts.h"

static void print_usage(void)
{
    hsy_putstr(USAGE_MSG);
}

bool engine_usage(engine_t *engine)
{
    if (engine->argc > 1) {
        print_usage();
        return (true);
    }
    return (false);
}