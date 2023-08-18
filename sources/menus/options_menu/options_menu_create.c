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
#include "menus_id.h"
#include "hsy.h"

menu_t *options_menu_create(input_t *input, menu_t *parent)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->name = hsy_strdup("");
    new->id = M_OPTIONS;
    new->opt.selection = 0;
    new->opt.parent = parent;
    new->opt.save_next = false;
    new->input = input;
    new->funcs = options_menu_funcs;
    return (new);
}