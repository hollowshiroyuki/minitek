/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "entities/entity.h"

void entities_draw(entity_t *list, screen_t *screen)
{
    while (list) {
        if (list->funcs.draw) {
            (*list->funcs.draw)(list, screen);
        }
    }
}