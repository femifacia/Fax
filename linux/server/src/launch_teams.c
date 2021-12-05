/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** launch_teams
*/

#include "../include/my.h"

void accept_connection(t_control *control)
{
    int ret = 0;
    t_client *client = NULL;
    socklen_t *len = (socklen_t *)&control->addr_len;
    struct sockaddr *adr = (struct sockaddr *)&(control->addr_in);

    if (FD_ISSET(control->highest_socket, &(control->fds))) {
        ret = accept(control->highest_socket, adr, len);
        if (ret < 0)
            exit_error("accept");
        client = create_client(ret);
        add_client_list(control, client);
    }
}

void select_connection(t_control *control)
{
    int max_fd = control->highest_socket;
    t_client *client = control->head_client;
    int ret = 0;

    FD_ZERO(&(control->fds));
    FD_SET(control->highest_socket, &(control->fds));
    while (client) {
        if (client->fd > 0)
            FD_SET(client->fd, &(control->fds));
        if (client->fd > max_fd)
            max_fd = client->fd;
        client = client->next;
    }
    ret = select(max_fd + 1, &(control->fds), NULL, NULL, NULL);
    if (ret < 0 && errno != EINTR)
        write(1, "select error\n", 13);
    accept_connection(control);
}

void manage_connection(t_control *control)
{
    t_client *client = control->head_client;

    while (client) {
        if (FD_ISSET(client->fd, &(control->fds)))
            manage_client(client, control);
        client = client->next;
    }
}

void launch_teams(t_control *control)
{
    while (1) {
        select_connection(control);
        manage_connection(control);
        save_info(control);
    }
}