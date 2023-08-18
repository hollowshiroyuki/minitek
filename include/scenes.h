/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef SCENES_H_
#define SCENES_H_

#include "rpg.h"
#include "game.h"

enum scene_id_e
{
    S_MENU,
    S_GAME,
    S_COUNT /*This one absolutely need to be the last !*/
};

static const scene_t scenes[] = {
    {
        .init = main_menu_init,
        .update = main_menu_update,
        .event = main_menu_event,
        .draw = main_menu_draw,
        .destroy = main_menu_destroy
    },
    {
        .init = game_init,
        .update = game_update,
        .draw = game_draw,
        .destroy = game_destroy
    }
};

#endif /* SCENES_H_ */