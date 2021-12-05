/*
** EPITECH PROJECT, 2020
** my_array_len
** File description:
** return the size of a array
*/

#include "../include/my.h"

int my_array_len(char **array)
{
    int size = 0;
    int i = 0;

    while (array[i] != NULL) {
        i++;
        size++;
    }
    return (size);
}
