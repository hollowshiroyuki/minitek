/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void asset_manager_destroy(engine_t *engine)
{
    if (engine->assets.entities)
        sfTexture_destroy(engine->assets.entities);
    if (engine->assets.gui)
        sfTexture_destroy(engine->assets.gui);
    if (engine->assets.items)
        sfTexture_destroy(engine->assets.items);
    if (engine->assets.tiles)
        sfTexture_destroy(engine->assets.tiles);
}