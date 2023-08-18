/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/workbench.h"
#include "universe.h"
#include <stdio.h>

bool workbench_use(entity_t *self, entity_t *player, int dir)
{
    universe_t *uni = player->mob.pla.universe;
    recipe_t *recipes = uni->craft->workbench;
    menu_t *craft_menu = crafting_menu_create(recipes, player, "Crafting");

    printf("Workbench\n");
    universe_set_menu(uni, craft_menu);
    return (true);
}