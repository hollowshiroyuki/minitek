/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

sfView *view_ratio(sfView *view, int width, int height)
{
    sfVector2f v_size = sfView_getSize(view);
    float w_ratio = width / (float)height;
    float v_ratio = v_size.x / v_size.y;
    sfVector2f size = {1.0, 1.0};
    sfVector2f pos = {0.0, 0.0};

    if (w_ratio > v_ratio) {
        size.x = v_ratio / w_ratio;
        pos.x = (1 - size.x) / 2.0;
    } else {
        size.y = w_ratio / v_ratio;
        pos.y = (1 - size.y) / 2.0;
    }
    sfView_setViewport(view, (sfFloatRect){pos.x, pos.y, size.x, size.y});
    return (view);
}