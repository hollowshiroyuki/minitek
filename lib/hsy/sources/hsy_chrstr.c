/*
** EPITECH PROJECT, 2020
** hsy_chrstr
** File description:
** r/ProgrammerHumor
*/

char *hsy_chrstr(char c, char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            return ((char *)(str + i));
        }
    }
    return (0);
}
