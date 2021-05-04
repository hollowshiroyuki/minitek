/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles_id.h"
#include "tiles/tile.h"
#include "tiles/dirt.h"
#include "tiles/hole.h"
#include "tiles/stair_up.h"
#include "tiles/stair_down.h"
#include "tiles/water.h"
#include "tiles/grass.h"
#include "tiles/sand.h"
#include "tiles/rock.h"
#include "tiles/cactus.h"
#include "tiles/tree.h"
#include "tiles/flower.h"
#include "tiles.h"

const tile_t *tiles[T_COUNT] = {
    &dirt,
    &hole,
    &stair_up,
    &stair_down,
    &water,
    &grass,
    &sand,
    &cactus,
    &rock,
    &tree,
    &flower
};