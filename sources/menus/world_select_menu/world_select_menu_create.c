/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "menus/menu.h"
#include "menus_id.h"
#include "menus/world_select_menu.h"
#include "universe.h"
#include "hsy.h"

static DIR *open_saves_dir(void)
{
    DIR *dir = opendir("./saves");

    if (!dir) {
        hsy_fd_putstr(2, "Can't acces ./saves/ folder.\n");
        hsy_fd_putstr(2, "You won't be able to load or save words!\n");
        return (0);
    }
    return (dir);
}

static bool read_saves_dir(world_entry_t **entries)
{
    DIR *dir;
    struct dirent *entry;
    int i = 1;

    if (!(dir = open_saves_dir()))
        return (false);
    while ((i < 15) && (entry = readdir(dir))) {
        if (entry->d_name[0] == '.')
            continue;
        if (hsy_strlen(entry->d_name) > 20 || entry->d_type != DT_REG)
            continue;
        entries[i] = malloc(sizeof(world_entry_t));
        entries[i]->error = false;
        hsy_strcpy(entries[i]->name, entry->d_name);
        i++;
    }
    closedir(dir);
    return (true);
}

menu_t *world_select_menu_create(input_t *input, menu_t *parent)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_WORLD_SELECT;
    new->name = hsy_strdup("");
    new->input = input;
    new->wsm.parent = parent;
    new->wsm.worlds[0] = malloc(sizeof(world_entry_t));
    hsy_strcpy(new->wsm.worlds[0]->name, "Create World");
    new->wsm.worlds[0]->error = false;
    read_saves_dir(new->wsm.worlds);
    new->funcs = world_select_menu_funcs;
    return (new);
}