/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef LEVEL_GEN_H_
#define LEVEL_GEN_H_

#include <SFML/Graphics.h>

#define ABS(x)((x < 0) ? (-x) : (x))

typedef struct maps_s
{
    int *map;
    int *data;
} maps_t;

typedef struct level_gen_s
{
    double *values;
    sfVector2i size;
} level_gen_t;

level_gen_t *level_gen_create(int w, int h, int feature_size);
double level_gen_sample(level_gen_t *lg, int x, int y);
void level_gen_set_sample(level_gen_t *lg, int x, int y, double value);
int **level_gen_create_and_validate_top_map(level_gen_t lg, int w, int h);
maps_t level_gen_create_top_map(int w, int h);
void level_gen_destroy(level_gen_t *lg);
#endif