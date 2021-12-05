/*
** EPITECH PROJECT, 2021
** client
** File description:
** recup_in_arr
*/

#include "../include/my.h"

char **cut_str_quote(char *str)
{
    int len = strlen(str);
    char **arr = NULL;
    int size = count_char(str, '\"'), count = 1;
    int i = 0;

    size /= 2;
    arr = (char **)malloc(sizeof(char *) * (size + 2));
    for (; str[i] && str[i] == ' '; i++);
    arr[0] = my_strdup_char(&str[i], ' ');
    for (; i < len; i++) {
        for (; str[i] && str[i] != '\"'; i++);
        if (!str[i])
            break;
        i++;
        arr[count] = my_strdup_char(&str[i], '\"');
        count++;
        for (; str[i] && str[i] != '\"'; i++);
    }
    arr[count] = NULL;
    return (arr);
}

char **recup_in_arr(char *str)
{
    char **arr = NULL;
    int size = count_char(str, '\"');

    if (!size) {
        arr = cut_str_array(str, ' ');
        return (arr);
    }
    return (cut_str_quote(str));
}