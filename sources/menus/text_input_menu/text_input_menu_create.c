/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus/title_menu.h"
#include "universe.h"
#include "hsy.h"

menu_t *text_input_menu_create(char *dest, int len, menu_t **parent)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->name = hsy_strdup("");
    new->title.data = data;
    new->funcs = title_menu_funcs;
    return (new);
}