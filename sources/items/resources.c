/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/resource.h"
#include "resources_id.h"
#include "tiles/tile.h"
#include "tiles/dirt.h"
#include "tiles/water.h"
#include "tiles/hole.h"

/* Plantable resources (yes, walls, planks etc are "plantable")*/
const resource_t r_dirt = {
    .id = R_DIRT,
    .tex = 0,
    .plant.target = (tile_t *)(&dirt),
    .plant.sources = {
        (tile_t *)(&hole),
        (tile_t *)(&water)
    },
    .interact = plant_interact
};

/* Common resources */
const resource_t wood = {
    .id = R_WOOD,
    .tex = 1,
    .interact = resource_interact
};

/* Consumables */
const resource_t bread = {
    .id = R_BREAD,
    .tex = 7,
    .food.heal = 2,
    .food.stamina_cost = 5,
    .interact = food_interact
};