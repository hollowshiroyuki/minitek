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
    .name = "Dirt",
    .tex = 0,
    .plant.target = (tile_t *)(&dirt),
    .plant.sources = {
        (tile_t *)(&hole),
        (tile_t *)(&water)
    },
    .interact = plant_interact
};

/* Common resources */
const resource_t r_wood = {
    .id = R_WOOD,
    .name = "Wood",
    .tex = 1,
    .interact = resource_interact
};

const resource_t r_stone = {
    .id = R_STONE,
    .name = "Stone",
    .tex = 2,
    .interact = resource_interact
};

/* Consumables */
const resource_t r_bread = {
    .id = R_BREAD,
    .name = "Bread",
    .tex = 7,
    .food.heal = 2,
    .food.stamina_cost = 5,
    .interact = food_interact
};

const resource_t r_apple = {
    .id = R_APPLE,
    .name = "Apple",
    .tex = 16,
    .food.heal = 1,
    .food.stamina_cost = 1,
    .interact = food_interact
};