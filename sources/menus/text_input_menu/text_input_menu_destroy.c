/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "menus/menu.h"

void text_input_menu_destroy(menu_t *self)
{
    self->input->buf = 0;
    self->input->buf_len = 0;
    self->input->buf_pos = 0;
    menu_destroy(self);
}