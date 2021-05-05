/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"
#include "resources/item.h"
#include "universe.h"
/*
void spiral(menu_t *menu)
{
    int X, Y;
    int x,y,dx,dy;
    x = y = dx =0;
    dy = -1;
    int t = (X > Y) ? X : Y;
    int maxI = t*t;
    for(int i = 0; i < maxI; i++){
        if ((-X / 2 <= x) && (x <= X / 2) && (-Y / 2 <= y) && (y <= Y / 2)) {
            return;
        }
        if( (x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1 - y))) {
            t = dx;
            dx = -dy;
            dy = t;
        }
        x += dx;
        y += dy;
    }
}
*/
void floor_change_menu_tick(menu_t *self)
{
    self->flc.time += 2;
    if (self->flc.time == 30)
        universe_change_floor(self->universe, self->flc.dir);
    if (self->flc.time == 60) {
        universe_set_menu(self->universe, self);
        (self->funcs.destroy)(self);
    }
    //spiral();
}