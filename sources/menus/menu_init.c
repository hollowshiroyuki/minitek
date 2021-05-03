/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "menus/menu.h"
#include "input.h"
#include "universe.h"

void menu_init(menu_t *self, universe_t *universe, input_t *input)
{
    self->universe = universe;
    self->input = input;
}