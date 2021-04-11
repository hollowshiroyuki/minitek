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
void level_gen_destroy(level_gen_t *lg);

/* Top Floor Files (Overworld) */
maps_t level_gen_create_and_validate_top_map(int w, int h);
maps_t level_gen_create_top_map(int w, int h);
void generate_sand(int *m, sfVector2i s);
void generate_island(level_gen_t *n[5], int *m, sfVector2i s);
void generate_trees(int *m, sfVector2i s);
void generate_cactus(int *m, sfVector2i s);
void generate_flowers(maps_t m, sfVector2i s);

/* Underground Files */
maps_t level_gen_create_underground_map(int w, int h, int depth);
void generate_cave(level_gen_t *n[11], int *m, sfVector2i s, int depth);
void generate_ores(int *m, sfVector2i s, int depth);

#endif