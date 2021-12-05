/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_login
*/

#include "../include/my.h"

void error_login(char **arr)
{
    if (!strcmp(arr[1], "connected"))
        client_error_already_exist();
}

void logg_client(t_client *client, char **arr)
{
    client_event_logged_in(arr[0], arr[1]);
    client->name = strdup(arr[1]);
    client->uid = strdup(arr[0]);
    client->is_logged = 1;
}

void send_log_request(t_client *client, char **arr)
{
    char str[1084];

    sprintf(str, "%s %s", arr[0], arr[1]);
    my_send(client->fd, str);
}

void launch_login(t_client *client, char **arg)
{
    char str[1024];
    int ret = 0;
    char **arr = NULL;
    int size = my_array_len(arg);

    if (size != 2) {
        client_error_unauthorized();
        return ;
    }
    send_log_request(client, arg);
    ret = read(client->fd, str, 1024);
    str[ret] = '\0';
    arr = cut_str_array(str, ' ');
    if (!arr)
        return;
    if (!strcmp(arr[0], "ERROR"))
        error_login(arr);
    else
        logg_client(client, arr);
    free_array(arr);
}