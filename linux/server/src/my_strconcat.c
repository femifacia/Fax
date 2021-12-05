/*
** EPITECH PROJECT, 2020
** my_strconcat
** File description:
** concat the first str into the second
*/

#include "../include/my.h"

char *my_strconcat(char *str2, char *str1)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int size = size1 + size2 + 1;
    char *str = (char *)malloc(sizeof(char) * size);

    for (int i = 0; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++)
        str[i + size1] = str2[i];
    str[size - 1] = '\0';
    return (str);
}
