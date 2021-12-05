/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print a char *
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, strlen(str));
}
