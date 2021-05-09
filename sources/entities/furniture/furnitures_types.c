/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "entities_id.h"
#include "random.h"
#include "entities/furniture.h"
#include "entities/workbench.h"
#include "entities/entity.h"

const furniture_type_t workbench_type = {
    .id = F_WORKBENCH,
    .name = "Workbench",
    .tex = 4,
    .funcs =  (entity_funcs_t *)&workbench_funcs
};

const furniture_type_t oven_type = {
    .id = F_OVEN,
    .name = "Oven",
    .tex = 4,
    .funcs = (entity_funcs_t *)&workbench_funcs
};

const furniture_type_t *furnitures_types[] = {
    &workbench_type,
    &oven_type
};