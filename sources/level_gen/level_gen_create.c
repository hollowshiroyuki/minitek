/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"
#include "random.h"

static void init_values(level_gen_t *lg, int feature_size)
{
    for (int y = 0; y < lg->size.x; y += feature_size) {
        for (int x = 0; x < lg->size.x; x += feature_size) {
            level_gen_set_sample(lg, x, y, random_float() * 2 - 1);
        }
    }
}

static void first_pass(level_gen_t *lg, int s_sz, int sc, int half_s)
{
    double s[5];
    double sum = 0;

    for (int y = 0; y < lg->size.x; y += s_sz) {
        for (int x = 0; x < lg->size.x; x += s_sz) {
            s[0] = level_gen_sample(lg, x, y);
            s[1] = level_gen_sample(lg, x + s_sz, y);
            s[2] = level_gen_sample(lg, x, y + s_sz);
            s[3] = level_gen_sample(lg, x + s_sz, y + s_sz);
            sum = s[0] + s[1] + s[2] + s[3];
            s[4] = sum / 4.0 + (random_float() * 2 - 1) * s_sz * sc;
            level_gen_set_sample(lg, x + half_s, y + half_s, s[4]);
        }
    }
}

static void second_pass(level_gen_t *lg, int s_sz, int sc, int half_s)
{
    double s[8];
    double sum1;
    double sum2;

    for (int y = 0; y < lg->size.x; y += s_sz) {
        for (int x = 0; x < lg->size.x; x += s_sz) {
            s[0] = level_gen_sample(lg, x, y);
            s[1] = level_gen_sample(lg, x + s_sz, y);
            s[2] = level_gen_sample(lg, x, y + s_sz);
            s[3] = level_gen_sample(lg, x + half_s, y + half_s);
            s[4] = level_gen_sample(lg, x + half_s, y - half_s);
            s[5] = level_gen_sample(lg, x - half_s, y + half_s);
            sum1 = (s[0] + s[1] + s[3] + s[4]);
            sum2 = (s[0] + s[2] + s[3] + s[5]);
            s[7] = sum1 / 4.0 + (random_float() * 2 - 1) * s_sz * sc * 0.5;
            s[6] = sum2 / 4.0 + (random_float() * 2 - 1) * s_sz * sc * 0.5;
            level_gen_set_sample(lg, x + half_s, y, s[7]);
            level_gen_set_sample(lg, x, y + half_s, s[6]);
        }
    }
}

static void generate_noise(level_gen_t *lg, int feature_size)
{
    int step_size = feature_size;
    double scale = 1.0 / lg->size.x;
    double scale_mod = 1;
    int half_step = step_size / 2;

    do {
        half_step = step_size / 2;
        first_pass(lg, step_size, scale, half_step);
        second_pass(lg, step_size, scale, half_step);
        step_size /= 2;
        scale *= (scale_mod + 0.8);
        scale_mod *= 0.3;
    } while (step_size > 1);
}

level_gen_t *level_gen_create(int w, int h, int feature_size)
{
    level_gen_t *lg = malloc(sizeof(level_gen_t));
    double *values = malloc(sizeof(double) * w * h);

    if (!lg || !values)
        return (0);
    lg->size = (sfVector2i){w, h};
    lg->values = values;
    init_values(lg, feature_size);
    generate_noise(lg, feature_size);
    return (lg);
}