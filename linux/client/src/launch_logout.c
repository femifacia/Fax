/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_logout
*/

#include "../include/my.h"

void logout_connected(t_client *client)
{
    my_send(client->fd, "/logout");
    client_event_logged_out(client->uid, client->name);
    client->is_connected = 0;
}

void logout_disconnected(t_client *client)
{
    my_send(client->fd, "/logout");
    client->is_connected = 0;
}

void launch_logout(t_client *client, char **arg)
{
    if (!arg) {
        if (client->is_logged)
            logout_connected(client);
        else
            logout_disconnected(client);
        return;
    }
    if (arg[1]) {
        client_error_unauthorized();
        return;
    }
    if (client->is_logged)
        logout_connected(client);
    else
        logout_disconnected(client);
}