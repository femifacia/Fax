/*
** EPITECH PROJECT, 2020
** cut_str_array
** File description:
** cut an string into a array with a copy char
*/

#include "../include/my.h"

char *my_strdup_char(char *str, char c)
{
    int size = 0;
    char *new_str = NULL;

    for (int i = 0; str[i] && str[i] != c; i++)
        size++;
    new_str = (char *)malloc(sizeof(char) * (size + 1));
    for (int i = 0; str[i] && str[i] != c; i++)
        new_str[i] = str[i];
    new_str[size] = '\0';
    return (new_str);
}

int get_arr_size(char *str, char c)
{
    int size = ((str) ? strlen(str) : 0);
    int count = 0;
    int i = 0;

    if (!size)
        return (0);
    for (; str[i] && str[i] == c; i++);
    if (!str[i])
        return (0);
    while (i < size) {
        if (str[i])
            count++;
        while (str[i] && str[i] != c)
            i++;
        while (str[i] && str[i] == c)
            i++;
    }
    return (count);
}

char **cut_str_array(char *str, char c)
{
    int size = get_arr_size(str, c);
    char **array = NULL;
    int i = 0;

    array = (char **)malloc(sizeof(char *) * (size + 1));
    if (size) {
        for (; str[i] && str[i] == c; i++);
        for (int count = 0; count < size; count++) {
            array[count] = my_strdup_char(&str[i], c);
            for (; str[i] && str[i] != c; i++);
            for (; str[i] && str[i] == c; i++);
        }
    }
    array[size] = NULL;
    return (array);
}
