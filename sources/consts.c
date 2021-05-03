/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "consts.h"

// Ratio must be 4 : 3
const int scale = 69;
const sfVector2i render_size = {4 * scale , 3 * scale};
// Max number of entities per tile, more will require more memory !
// If there's more entities on one tile, only the fist n entities will be
// updated on player action.
const int entities_per_tile = 10;
const char *window_name = "MiniTek | MyRPG";