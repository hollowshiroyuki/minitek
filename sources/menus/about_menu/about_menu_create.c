/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus_id.h"
#include "universe.h"
#include "hsy.h"
#include <stdio.h>

menu_t *about_menu_create(input_t *input, menu_t *parent)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_ABOUT;
    new->input = input;
    new->about.parent = parent;
    new->name = hsy_strdup("");
    new->funcs = about_menu_funcs;
    return (new);
}