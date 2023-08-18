/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "consts.h"

void asset_manager_init(engine_t *engine)
{
    engine->assets.entities = sfTexture_createFromFile(TEX_ENTITIES, NULL);
    engine->assets.gui = sfTexture_createFromFile(TEX_GUI, NULL);
    engine->assets.items = sfTexture_createFromFile(TEX_ITEMS, NULL);
    engine->assets.tiles = sfTexture_createFromFile(TEX_TILES, NULL);
}