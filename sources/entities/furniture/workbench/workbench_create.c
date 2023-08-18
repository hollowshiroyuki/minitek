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

entity_t *workbench_create(void)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->id = E_FURNITURE;
    new->fur.id = E_WORKBENCH;
    furniture_init(new, "Workbench");
    new->fur.tex = 4;
    new->box.x = 3;
    new->box.y = 2;
    new->fur.push_dir = -1;
    entity_funcs_combine(&new->funcs, &workbench_funcs, &furniture_funcs);
    return (new);
}