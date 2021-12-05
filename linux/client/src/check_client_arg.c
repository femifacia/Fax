/*
** EPITECH PROJECT, 2021
** client
** File description:
** check_client_arg
*/

#include "../include/my.h"

bool final_arg_check(char *arg)
{
    int i = 0;

    for (i = 0; arg[i] == ' '; i++);
    return ((arg[i] ? 0 : 1));
}

bool check_client_quote(char *arg, int nb, int nbr)
{
    int i = 0;

    if (nbr / 2 != nb || nbr % 2)
        return (0);
    for (int a = 0; a < nb; a++) {
        if (arg[0] != '\"')
            return (0);
        for (i = 1; arg[i] && arg[i] != '\"'; i++);
        if (!arg[i])
            return (0);
        if (!arg[i + 1] && a + 1 < nb)
            return (0);
        if (arg[i + 1] != ' ' && a + 1 < nb)
            return (0);
        arg = ((arg[i + 1]) ? &arg[i + 2] : &arg[i + 1]);
    }
    return (final_arg_check(arg));
}

bool check_client_arg(char *arg, int nb)
{
    int nbr = count_char(arg, '\"');
    char **array = NULL;

    if (nbr)
        return (check_client_quote(arg, nb, nbr));
    array = cut_str_array(arg, ' ');
    nbr = my_array_len(array);
    for (int i = 0; array[i]; i++)
        printf("[%s] %d\n", array[i], i);
    free_array(array);
    if (nbr != nb) {
        write(1, "AH\n", 3);
        printf("%d\n", nbr);
        return (0);
    }
    return (1);
}