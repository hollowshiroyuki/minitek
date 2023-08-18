/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "resources/item.h"
#include "resources/tool_item.h"
#include "items_id.h"
#include "hsy.h"

item_t *tool_item_create(tool_type_t *type, int level)
{
    item_t *new = malloc(sizeof(item_t));

    memset(new, 0, sizeof(item_t));
    new->id = I_TOOL;
    new->tool.type = type;
    new->tool.level = level;
    new->tool.max_level = 4;
    hsy_strcat(new->tool.name, level_names[level]);
    hsy_strcat(new->tool.name, " ");
    hsy_strcat(new->tool.name, type->name);
    item_funcs_combine(&new->funcs, &tool_item_funcs);
    return (new);
}