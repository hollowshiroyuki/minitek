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

/* S_COUNT absolutely needs to be the last !*/
enum scene_id_e
{
    S_MENU,
    S_GAME,
    S_COUNT
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