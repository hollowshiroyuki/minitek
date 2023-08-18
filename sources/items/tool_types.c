/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/tool_item.h"

const char *level_names[] =
{
    "Wood",
    "Rock",
    "Iron",
    "Gold",
    "Gem"
};

const tool_type_t shovel_type = {
    .id = TT_SHOVEL,
    .name = "Shovel",
    .tex = 416
};

const tool_type_t pick_type = {
    .id = TT_PICK,
    .name = "Pick",
    .tex = 448
};

const tool_type_t hoe_type = {
    .id = TT_HOE,
    .name = "Hoe",
    .tex = 416
};

const tool_type_t sword_type = {
    .id = TT_SWORD,
    .name = "Sword",
    .tex = 416
};

const tool_type_t axe_type = {
    .id = TT_AXE,
    .name = "Axe",
    .tex = 416
};

const tool_type_t big_sword_type = {
    .id = TT_HEAVY_SWORD,
    .name = "B.Sword",
    .tex = 416
};