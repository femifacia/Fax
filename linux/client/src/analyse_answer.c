/*
** EPITECH PROJECT, 2021
** client
** File description:
** analyse_answer
*/

#include "../include/my.h"

void launch_recv(char **arg)
{
    if (!strcmp(arg[0], "send"))
        recv_send(arg);
    if (!strcmp(arg[0], "logout"))
        recv_logout(arg);
    if (!strcmp(arg[0], "login"))
        recv_login(arg);
}

void analyse_answer(t_client *client)
{
    char str[1024];
    int ret = read(client->fd, str, 1024);
    char **arg = NULL;

    str[ret] = '\0';
    if (!strcmp(str, "/logout")) {
        launch_logout(client, NULL);
        return;
    }
    if (str[0] < 'a' || str[0] > 'z')
        arg = cut_str_array(str, str[0]);
    else
        arg = cut_str_array(str, ' ');
    launch_recv(arg);
    free_array(arg);
}