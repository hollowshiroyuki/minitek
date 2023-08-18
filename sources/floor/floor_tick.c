/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "random.h"
#include "floor.h"
#include "entities/player.h"

void floor_tick(floor_t *self)
{
    player_tick(self->player);
    self->tickCount++;
}