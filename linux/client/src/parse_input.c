/*
** EPITECH PROJECT, 2021
** client
** File description:
** parse_input
*/

#include "../include/my.h"

char get_del(char *del, char *input)
{
    int count = 0;

    for (int i = 0; del[i]; i++) {
        count = count_char(input, del[i]);
        if (!count)
            return (del[i]);
    }
    return ('\\');
}

void passe_space(char *str, int *i, char c)
{
    while (str[*i] && str[*i] != ' ')
        *i += 1;
    if (str[*i])
        str[*i] = c;
}

void passe_quote(char *str, int *i)
{
    *i += 1;
    while (str[*i] && str[*i] != '\"')
        *i += 1;
}

void transforme_input(char *input, char c)
{
    int size = strlen(input);

    for (int i = 0; i < size; i++) {
        for (; input[i] == ' '; i++)
            input[i] = c;
        if (input[i] == '\"')
            passe_quote(input, &i);
        else
            passe_space(input, &i, c);
    }
}

char **parse_input(char *input)
{
    char **arg = NULL;
    char *del = "-%@+";
    char c = get_del(del, input);

    transforme_input(input, c);
    arg = cut_str_array(input, c);
    return (arg);
}