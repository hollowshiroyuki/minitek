/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus/text_input_menu.h"
#include "universe.h"
#include "menus_id.h"
#include "hsy.h"

menu_t *text_input_menu_create(char *dest, int len, char *name, menu_t *parent)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->id = M_TEXT_INPUT;
    new->name = hsy_strdup(name);
    new->input = parent->input;
    new->input->buf = dest;
    new->ti.buf = dest;
    new->ti.buf_len = len;
    new->input->buf_len = len;
    new->input->buf_pos = 0;
    new->input->buf[0] = '\0';
    new->ti.parent = parent;
    new->funcs = text_input_menu_funcs;
    return (new);
}