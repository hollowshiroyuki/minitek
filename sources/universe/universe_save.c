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

static int open_save_file(char *filename)
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

void save_seeds(int seeds[2], int fd)
{
    hsy_fd_putnbr(fd, seeds[0]);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, seeds[1]);
    hsy_fd_putstr(fd, "\n");
}

bool universe_save(universe_t *self)
{
    int fd = open_save_file(self->name);

    if (!fd)
        return (false);
    hsy_putstr("Saving ! The game will hang during the save.\n");
    save_seeds(self->seeds, fd);
    player_save(self->player, fd);
    for (int i = 0; i < 15 && self->floors[i]; i++) {
        floor_save(self->floors[i], fd);
        if (self->floors[i + 1])
            hsy_fd_putstr(fd, "\n");
    }
    close(fd);
    hsy_putstr("Done ! It's now safe to continue playing.\n");
    return (true);
}