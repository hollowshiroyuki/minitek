/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

int main(int argc, char **argv, char **envp)
{
    engine_t engine = {.argc = argc, .argv = argv, .envp = envp};

    engine_init(&engine);
    if (engine.state == EN_RUN)
        engine_start(&engine);
    return (engine.ret);
}
