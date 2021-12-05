/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** launch_logout
*/

#include "../include/my.h"

void logout_unconnected(t_client *client)
{
    close(client->fd);
    client->fd = 0;
}

void logout_connected(t_client *client)
{
    server_event_user_logged_out(client->uid);
    close(client->fd);
    client->fd = 0;
    free(client->name);
    free(client->uid);
    client->name = NULL;
    client->uid = NULL;
    client->info->status -= 1;
}

void launch_logout(t_control *control, t_client *client, char *arg)
{
    t_client *elm = control->head_client;
    char str[1024];

    sprintf(str, "logout %s %s", client->uid, client->name);
    if (client->is_logged)
        logout_connected(client);
    else
        logout_unconnected(client);
    for (; elm; elm = elm->next) {
        if (!elm->fd)
            continue;
        if (!elm->is_logged)
            continue;
        my_send(elm->fd, str);
    }
}