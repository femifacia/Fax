/*
** EPITECH PROJECT, 2021
** client
** File description:
** remove_quote
*/

#include "../include/my.h"

void remove_quote(char **arg)
{
    char *str = NULL;

    for (int i = 0; arg[i]; i++) {
        if (arg[i][0] == '\"') {
            str = strdup(&(arg[i][1]));
            str[strlen(str) - 1] = '\0';
            free(arg[i]);
            arg[i] = str;
        }
    }
}