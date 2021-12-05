/*
** EPITECH PROJECT, 2021
** server
** File description:
** launch_user
*/

#include "../include/my.h"

void launch_user(t_control *control, t_client *client, char *arg)
{
    t_info *info = NULL;
    int status = 0;
    char str[1024];

    info = find_info_uid(control->head_info, arg);
    if (!info) {
        my_send(client->fd, "ERROR");
        return;
    }
    status = ((info->status > 0) ? 1 : 0);
    sprintf(str, "%s %s %d", info->uid, info->name, status);
    my_send(client->fd, str);
}