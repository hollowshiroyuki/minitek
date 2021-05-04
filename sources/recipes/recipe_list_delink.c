/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "recipes/craft.h"

// Used to destroy a copied list
void recipe_list_delink(recipe_t *list)
{
    recipe_t *tmp;

    while (list) {
        tmp = list->next;
        free(list->result);
        free(list);
        list = tmp;
    }
}