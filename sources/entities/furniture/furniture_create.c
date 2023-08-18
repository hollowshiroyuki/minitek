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

entity_t *furniture_create(int furniture_id)
{
    entity_t *new = malloc(sizeof(entity_t));
    entity_funcs_t *funcs = furnitures_types[furniture_id]->funcs;

    if (!new || furniture_id >= F_COUNT)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->id = E_FURNITURE;
    new->fur.id = furniture_id;
    furniture_init(new, furnitures_types[furniture_id]->name);
    new->fur.tex = furnitures_types[furniture_id]->tex;
    new->box.x = 3;
    new->box.y = 2;
    new->fur.push_dir = -1;
    entity_funcs_combine(&new->funcs, funcs, &furniture_funcs);
    return (new);
}