/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "screen.h"
#include <stdio.h>
#include "entities/entity.h"
#include "entities_id.h"
#include "consts.h"

static void bubble_sort(entity_t **list)
{
    int c = 0;
    int d = 0;
    entity_t *t = 0;
    int len = 0;

    for (int i = 0; list[i]; i++)
        len++;
    for (c = 0; c < len - 1; c++) {
        for (d = 0; d < len - c - 1; d++) {
            if (list[d]->pos.y > list[d + 1]->pos.y) {
                t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}

void floor_sort_and_draw(floor_t *self, screen_t *screen, entity_t **list)
{
    bubble_sort(list);
    for (int i = 0; list[i]; i++) {
        (*list[i]->funcs.draw)(list[i], screen);
    }
}