/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "entities.h"

int main(int ac, char **av, char **env)
{
    engine_t engine = {.argc = ac, .argv = av, .envp = env};

    if (engine_usage(&engine))
        return (engine.ret);
    engine_init(&engine);
    if (engine.state == EN_RUN)
        engine_start(&engine);
    return (engine.ret);
}
