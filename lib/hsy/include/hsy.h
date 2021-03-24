/*
** EPITECH PROJECT, 2020
** hsy.h
** File description:
** libhsy header file.
*/

#ifndef LIBHSY_H
#define LIBHSY_H
/*
** INCLUDES
*/
#include <sys/types.h>
#include <stddef.h>

/*
** DISPLAY FUNCTIONS
*/
void hsy_fd_putchar(int fd, char c);
void hsy_putchar(char c);
ssize_t hsy_fd_putstr(int fd, char const *str);
ssize_t hsy_putstr(char const *str);
ssize_t hsy_fd_putnbr(int fd, int nb);
ssize_t hsy_putnbr(int nb);

/*
** MATHS FUNCTIONS
*/
int hsy_isneg(int nb);
void hsy_int_swap(int *a, int *b);
void hsy_sort_int_array(int *tab, int size);
int hsy_compute_power_rec(int nb, int power);
int hsy_compute_square_root(int nb);
int hsy_is_prime(int nb);
int hsy_find_prime_sup(int nb);

/*
** STRINGS FUNCTIONS
*/
size_t hsy_strlen(char const *str);
int hsy_getnbr(char const *str);
int hsy_atoi(char const *str);
char *hsy_strcpy(char *dest, char const *src);
char *hsy_strncpy(char *dest, char const *src, int n);
char *hsy_revstr(char *str);
char *hsy_strstr(char *str, char const *to_find);
int hsy_strcmp(char const *s1, char const *s2);
int hsy_strncmp(char const *s1, char const *s2, int nb);
char *hsy_strupcase(char *str);
char *hsy_strlowcase(char *str);
char *hsy_strcapitalize(char *str);
int hsy_str_isalpha(char const *str);
int hsy_str_isnum(char const *str);
int hsy_str_islower(char const *str);
int hsy_str_isupper(char const *str);
int hsy_str_isprintable(char const *str);
char *hsy_strcat(char *dest, char const *src);
char *hsy_strncat(char *dest, char const *src, int nb);
char **hsy_str_to_word_array(char const *str);
char *hsy_strdup(char const *str);
char *hsy_strndup(char const *str, size_t n);
int hsy_isspace(char c);
int hsy_strtol(char const *str, char **str_end);
unsigned int hsy_strtoul(char const *str, char **end_ptr);
char *hsy_chrstr(char c, char const *str);
int hsy_fd_printf(int fd, char const *format, ...);
#endif /*LIBHSY_H*/
