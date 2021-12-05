/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_users
*/

#include "../include/my.h"

void print_user(char *line)
{
    char **arg = cut_str_array(line, ' ');
    int size = my_array_len(arg);

    if (size != 3) {
        if (arg)
            free_array(arg);
        return;
    }
    client_print_users(arg[0], arg[1], atoi(arg[2]));
    free_array(arg);
}

void launch_users(t_client *client, char **arg)
{
    char str[2048];
    int ret = 0;
    char **arr = NULL;

    if (!client->is_logged) {
        client_error_unauthorized();
        return;
    }
    if (arg[1]) {
        error_arg();
        return;
    }
    client->str[client->delim] = ' ';
    my_send(client-> fd, arg[0]);
    ret = read(client->fd, str, 2048);
    str[ret] = '\0';
    arr = cut_str_array(str, '\n');
    for (int i = 0; arr[i]; i++)
        print_user(arr[i]);
    free_array(arr);
}