/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef LOADER_H_
#define LOADER_H_

int parse_atoi(char **str);
char *get_line(FILE *file, bool free);
char **str_split(char *str, char *delim);
char **str_split_count(char *str, char *delim, int *c);

bool player_load(entity_t **player, FILE *file);
bool inventory_load(inventory_t **inv, char *str);
bool item_load(item_t **itm, char *str);
bool resource_item_load(item_t **itm, char **split, int count);
bool furniture_item_load(item_t **itm, char **split, int count);
bool tool_item_load(item_t **itm, char **split, int count);
bool simple_mob_load(entity_t **e, char **split, int count);
bool mob_load(entity_t **e, char **split, int count);
bool furniture_load(entity_t **e, char **split, int count);
bool item_entity_load(entity_t **e, char **split, int count);
bool entity_load(entity_t **e, char *str);
bool floor_load(floor_t **floor, FILE *file);

#endif