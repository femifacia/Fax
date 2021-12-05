/*
** EPITECH PROJECT, 2020
** count_char
** File description:
** return the number of time c appear in str
*/

#include "../include/my.h"

int count_char(char *str, char c)
{
    int size = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            size++;
    }
    return (size);
}
