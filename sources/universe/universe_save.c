/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdbool.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "universe.h"
#include "hsy.h"
#include "floor.h"

int open_save_file(char *filename)
{
    char path[PATH_MAX];
    int fd;

    hsy_strcpy(path, "./saves/");
    hsy_strcat(path, filename);
    fd = open(path, O_TRUNC | O_WRONLY | O_CREAT);
    if (fd == -1) {
        hsy_fd_putstr(2, "Can't open folder or file. Can't save the game.\n");
        return (0);
    }
    return (fd);
}

bool universe_save(universe_t *self)
{
    int fd = open_save_file(self->name);

    if (!fd)
        return (false);
    hsy_putstr("Saving ! The game will hang during the save.\n");
    for (int i = 0; i < 15 && self->floors[i]; i++) {
        floor_save(self->floors[i], fd);
    }
    close(fd);
    hsy_putstr("Done ! It's now safe to continue playing.\n");
    return (true);
}