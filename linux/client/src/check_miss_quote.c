/*
** EPITECH PROJECT, 2021
** client
** File description:
** check_miss_quote
*/

#include "../include/my.h"

bool check_miss_quote(char *input)
{
    int i = 0;

    while (input[i]) {
        while (input[i] && input[i] != '\"')
            i++;
        if (!input[i])
            return (0);
        i = ((input[i]) ? i + 1 : i);
        while (input[i] && input[i] != '\"')
            i++;
        if (!input[i])
            return (1);
        i = ((input[i]) ? i + 1 : i);
    }
    return (0);
}