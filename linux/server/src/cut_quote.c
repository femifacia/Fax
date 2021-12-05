/*
** EPITECH PROJECT, 2021
** server
** File description:
** cut_quote
*/

#include "../include/my.h"

void cut_quote(char **arg)
{
    int nbr = count_char(*arg, '\"');

    if (!nbr)
        return ;
    *arg = &(arg[0][1]);
    arg[0][strlen(arg[0]) - 1] = '\0';
}