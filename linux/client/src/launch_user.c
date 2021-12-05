/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_user
*/

#include "../include/my.h"

void analyse_user_ans(char *str, char *uid)
{
    char **arr = NULL;

    if (!strcmp(str, "ERROR")) {
        client_error_unknown_user(uid);
        return;
    }
    arr = cut_str_array(str, ' ');
    client_print_user(arr[0], arr[1], atoi(arr[2]));
    free_array(arr);
}

void launch_user(t_client *client, char **arg)
{
    char str[1024];
    char mes[1024];
    int ret = 0;
    int len = my_array_len(arg);

    if (!client->is_logged) {
        client_error_unauthorized();
        return;
    }
    if (len != 2) {
        error_arg();
        return;
    }
    sprintf(mes, "%s %s", arg[0], arg[1]);
    my_send(client-> fd, mes);
    ret = read(client->fd, str, 1024);
    str[ret] = '\0';
    analyse_user_ans(str, arg[1]);
}