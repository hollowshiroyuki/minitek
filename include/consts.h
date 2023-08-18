/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef CONSTS_H_
#define CONSTS_H_

extern const sfVector2i render_size;
extern const char *window_name;

#define TEX_ENTITIES "./assets/entities.png"
#define TEX_GUI "./assets/gui.png"
#define TEX_ITEMS "./assets/items.png"
#define TEX_TILES "./assets/tiles.png"

#define USAGE_MSG "\
Usage: ./my_rpg [-h | --help]\n\
Simple Sandbox/RPG game, \"inspired\" by Minicraft.\n\
\n\
Start a new adventure in MiniTek !\n\
"

#endif