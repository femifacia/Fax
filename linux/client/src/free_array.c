/*
** EPITECH PROJECT, 2020
** free_array
** File description:
** free a char ** array
*/

#include "../include/my.h"

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
