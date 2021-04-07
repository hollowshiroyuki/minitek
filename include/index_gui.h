/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef GUI_INDEX_H_
#define GUI_INDEX_H_

#include <SFML/Graphics.h>

typedef enum gui_tex_id_e
{
    GUI_TEX_ERR,
    GUI_TEX_LOGO,
    GUI_TEX_FULL_HEART,
    GUI_TEX_FULL_ENERGY,
    GUI_TEX_FULL_FOOD,
    GUI_TEX_VER_SWIPE_1,
    GUI_TEX_HOR_SWIPE_1,
    GUI_TEX_BLUEPILL,
    GUI_TEX_REDPILL,
    GUI_TEX_EMPTY_HEART,
    GUI_TEX_EMPTY_ENERGY,
    GUI_TEX_EMPTY_FOOD,
    GUI_TEX_VER_SWIPE_2,
    GUI_TEX_ARROW,
    GUI_TEX_REGEN_ENERGY,
    GUI_TEX_SQUARE,
    GUI_TEX_PIZZA,
    GUI_TEX_MENU_CORNER,
    GUI_TEX_MENU_HOR,
    GUI_TEX_MENU_VER,
    GUI_TEX_MENU_BACK
} gui_tex_id_t;

static const sfIntRect gui_tex_index[] = {
/*   X, Y, SX, SY  */
    {248, 0, 8, 8}, /* Error Texture */
    {0, 0, 120, 16}, /* Logo */
    {0, 16, 8, 8}, /* Full Heart */
    {8, 16, 8, 8}, /* Full Energy */
    {16, 16, 8, 8}, /* Full Food */
    {24, 16, 8, 8}, /* Ver Swipe 1 */
    {32, 16, 8, 8}, /* Hor Swipe 1 */
    {40, 16, 8, 8}, /* Bluepill */
    {48, 16, 8, 8}, /* Redpill */
    {0, 24, 8, 8}, /* Empty Heart */
    {8, 24, 8, 8}, /* Empty Energy */
    {16, 24, 8, 8}, /* Empty Food */
    {24, 24, 8, 8}, /* Ver Swipe 2 */
    {32, 24, 8, 8}, /* Arrow Icon */
    {8, 32, 8, 8}, /* Regen Energy */
    {24, 32, 8, 8}, /* White Square */
    {32, 32, 8, 8}, /* Pizza ? */
    {0, 168, 8, 8}, /* Menu Corner */
    {8, 168, 8, 8}, /* Menu Hor */
    {16, 168, 8, 8}, /* Menu Ver */
    {24, 168, 8, 8} /* Menu Back */
};

#endif