/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "recipes/craft.h"

craft_t *craft_create(void)
{
    craft_t *new = malloc(sizeof(craft_t));

    memset(new, 0, sizeof(craft_t));
    new->workbench = workbench_recipes_create();
    //new->anvil = anvil_recipes_create();
    //new->oven = oven_recipes_create();
    //new->furnace = furnace_recipes_create();
    return (new);
}