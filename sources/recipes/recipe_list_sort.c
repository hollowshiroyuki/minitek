/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

static recipe_t *swap(recipe_t *p1, recipe_t *p2)
{
    recipe_t *tmp = p2->next;

    p2->next = p1;
    p2->result->next = p1->result;
    p1->result->next = (tmp) ? tmp->result : 0;
    p1->next = tmp;
    return (p2);
}

void recipe_list_sort(recipe_t **list)
{
    int list_len = recipe_list_size(*list);
    int swapped;
    recipe_t **head;
    recipe_t *tmp1 = *list;
    recipe_t *tmp2;

    for (int i = 0; i <= list_len; i++) {
        head = list;
        swapped = 0;
        for (int j = 0; j < list_len - i - 1; j++) {
            tmp1 = *head;
            tmp2 = tmp1->next;
            if (!tmp1->can_craft && tmp2->can_craft) {
                *head = swap(tmp1, tmp2);
                swapped++;
            }
        }
        if (!swapped)
            return;
    }
}